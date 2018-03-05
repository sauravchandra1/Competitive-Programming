#include <bits/stdc++.h>
using namespace std;

const int siz=1e4+4;

vector<int> grph[siz];
int lookup[siz];
stack<int> ent;
int ver=0;

#define pb push_back

void dfs(int source){
	int len=grph[source].size();
	lookup[source]=1;
	ver++;
	for(int i=0;i<len;i++){
		int temp=grph[source][i];
		if(!lookup[temp])
			dfs(temp);
	}
}
	
int main(){
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		grph[x].pb(y);
		grph[y].pb(x);
	}
	if(n!=m+1){
		printf("NO\n");
		return 0;
	}
	else
		dfs(x);
	if(ver==n)
		printf("YES\n");
	else 
		printf("NO\n");
	return 0;
}
		
		
