#include <bits/stdc++.h>
using namespace std;

const int siz=1e4+4;
vector<int> tree[siz];
int mx=-1,node=0;
int lookup[siz];

#define pb push_back

void dfs(int source,int val){
	lookup[source]=1;
	if(val>mx){
		mx=val;
		node=source;
	}
	int temp=tree[source].size(),next=0;
	for(int i=0;i<temp;i++){
		next=tree[source][i];
		if(!lookup[next])
			dfs(next,val+1);	
	}	
}

int main(){
	int ver;
	scanf("%d",&ver);
	int x,y;
	for(int i=0;i<ver-1;i++){
		scanf("%d%d",&x,&y);
		tree[x].pb(y);
		tree[y].pb(x);
	}
	dfs(x,0);
	memset(lookup,0,sizeof lookup);
	dfs(node,0);
	printf("%d\n",mx);
	return 0;
}
