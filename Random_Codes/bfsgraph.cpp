#include<bits/stdc++.h>
using namespace std;
int main(){
	int edge;
	cin>>edge;
	int x,y;
	vector<int> v1[10];
	queue<int> q;
	for(int i=0;i<edge;i++){
		cin>>x>>y;
		v1[x].push_back(y);
		v1[y].push_back(x);
	}
	for(int i=1;i<edge;i++){
		cout<<i<<"->";
		for(int j=0;j<v1[i].size();j++){
			cout<<v1[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=0;i<v1[1].size();i++){
		q.push(v1[1][i]);
	}	
	int arr[100];
	memset(arr,0,100*sizeof(arr[0]));
	cout<<"1 ";
	arr[1]=1;
	int temp=0;
	while(!q.empty()){
		temp=q.front();
		q.pop();
		for(int i=0;i<v1[temp].size();i++){
			if(arr[v1[temp][i]]==0)
				q.push(v1[temp][i]);
		}
		if(arr[temp]!=1){
			cout<<temp<<" ";
			arr[temp]=1;
		}
	}
	return 0;
}
/*
10
1 2
1 3
3 4
3 5
4 6
5 6
5 7
4 9
9 8
5 8
*/