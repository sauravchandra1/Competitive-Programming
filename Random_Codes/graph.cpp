#include<bits/stdc++.h>
using namespace std;
int main(){
	int edge;
	cin>>edge;
	int x,y;
	vector<int> v1[10];
	for(int i=0;i<edge;i++){
		cin>>x>>y;
		v1[x].push_back(y);
	}
	for(int i=1;i<edge;i++){
		cout<<i<<"->";
		for(int j=0;j<v1[i].size();j++){
			cout<<v1[i][j]<<" ";
		}
		cout<<endl;
	}	
	return 0;
}