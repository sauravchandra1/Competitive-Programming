#include<bits/stdc++.h>
using namespace std;

const int mx=1e5+5;

int main(){
	int test;
	scanf("%d",&test);

	while(test--){
		string s;
		vector<string> vs;
		queue <pair<int,int>> pos;
		pair<int,int> trol;
		int n,m;
		
		scanf("%d%d",&n,&m);
		
		int** arr=new int*[n];
		
		for(int i=0;i<n;i++)
			arr[i]=new int[m];

		int** track=new int*[n];
		
		for(int i=0;i<n;i++){
			track[i]=new int[m];
			memset(&track[i][0],0,m*(sizeof(track[i][0])));
		}

		for(int i=0;i<n;i++){
			cin>>s;
			vs.push_back(s);
		}
	
		for(int i=0;i<n;i++){
			s=vs[i];	

			for(unsigned int j=0;j<s.length();j++){
				arr[i][j]=int(s[j])-48;
			}
		}		
				
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){

				if(arr[i][j]==1){
					pos.push(make_pair(i,j));
					track[i][j]=1;
					arr[i][j]=0;
				}
				else
					arr[i][j]=mx;
			}
		}

		int i=0,j=0;

		while(!pos.empty()){

			trol=pos.front();
			pos.pop();
			i=trol.first;
			j=trol.second;

			if((i-1>=0)&&(i-1<n)&&(j>=0)&&(j<m)){

				if(track[i-1][j]==0){

					arr[i-1][j]=arr[i][j]+1;
					pos.push(make_pair(i-1,j));
					track[i-1][j]=1;
				}				
			}
			if((i>=0)&&(i<n)&&(j-1>=0)&&(j-1<m)){

				if(track[i][j-1]==0){

					arr[i][j-1]=arr[i][j]+1;
					pos.push(make_pair(i,j-1));
					track[i][j-1]=1;
				}
			}
			if((i+1>=0)&&(i+1<n)&&(j>=0)&&(j<m)){

				if(track[i+1][j]==0){

					arr[i+1][j]=arr[i][j]+1;
					pos.push(make_pair(i+1,j));
					track[i+1][j]=1;
				}
			}
			if((i>=0)&&(i<n)&&(j+1>=0)&&(j+1<m)){

				if(track[i][j+1]==0){

					arr[i][j+1]=arr[i][j]+1;
					pos.push(make_pair(i,j+1));
					track[i][j+1]=1;
				}
			}
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				printf("%d ",arr[i][j]);
			}
			printf("\n");
		}
		
	}

	return 0;
}
