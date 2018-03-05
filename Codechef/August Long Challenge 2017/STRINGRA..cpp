#include<bits/stdc++.h>
using namespace std;
 
int main(){
 
	int test;
	cin>>test;
 
	while(test--){
 
		int n,m;
		cin>>n>>m;
 
		vector<int> v[100005];
		int x,y;
 
		int* arr=new int[n+1];
		memset(arr,0,(n+1)*sizeof(arr[0]));
 
		int* lookup=new int[n+1];
		memset(lookup,0,(n+1)*sizeof(lookup[0]));
		
		int* chk=new int[n+1];
		memset(chk,0,(n+1)*sizeof(chk[0]));
 
		for(int i=0;i<m;i++){
 
			cin>>x>>y;
			v[x].push_back(y);
		}
 
		for(int i=0;i<n;i++)
			sort(v[i].begin(),v[i].end());
 
		map<int,int> mp[100005];
		map<int,int>::iterator it;
 
		int value=1,flag=0;
 
		for(unsigned int i=0;i<v[0].size();i++){
 
			arr[v[0][i]]=value;
			lookup[v[0][i]]=1;
 
			mp[1].insert(pair<int,int>(v[0][i],value));
 
			value++;
		}
 
		for(int i=1;i<n;i++){
 
			for(unsigned int j=0;j<v[i].size();j++){
 
				if(lookup[v[i][j]]==1){
 
					it=mp[i].find(v[i][j]);
 
					if(it->second){
 
						mp[i+1].insert(pair<int,int>(v[i][j],mp[i][v[i][j]]));
						mp[i].erase(v[i][j]);
					}
				}
				else{
 
					it=mp[i].begin();
 
					if((it->first)<v[i][j]){
 
						arr[v[i][j]]=arr[it->first];
						lookup[v[i][j]]=1;
 
						mp[i+1].insert(pair<int,int>(v[i][j],it->first));
					}
					else{
 
						cout<<"-1"<<endl;
						flag=1;
						break;
					}
 
 
				}
			}
 
			if(flag==1)
				break;
		}
 
		if(flag==1)
			continue;
 
		int sum=0;
 
		for(int i=0;i<n;i++){
 
			sum+=i+1-chk[arr[i+1]];
			chk[arr[i+1]]=i+1;
		}
 
		if(sum!=m){
 
			cout<<"-1"<<endl;
			flag=1;
			continue;
		}
 
		if(flag==0){
 
			for(int i=1;i<=n;i++){
 
				cout<<arr[i]<<" ";
			}
 
			cout<<endl;
		}
	}
 
	return 0;
}
  
