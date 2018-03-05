#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int lookup[2005];
vector<int> grph[2005];
char col[2005];
int flag=0,cnt=0;

void dfs(int source,char color){
	lookup[source]=1;
	col[source]=color;
	char rev_color;
	if(color=='W')
		rev_color='B';
	else 
		rev_color='W';
	int siz=grph[source].size();
	for(int i=0;i<siz;i++){
		int temp=grph[source][i];
		if(!lookup[temp])
			dfs(temp,rev_color);
		else{
			if(col[temp]==color)
				flag=1;
		}
	}
}
			
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		cnt++;
		flag=0;
		memset(lookup,0,sizeof lookup);
		memset(col,'0',sizeof col);
		for(int i=0;i<2004;i++)
			grph[i].clear();
		int vert,edge;
		scanf("%d %d",&vert,&edge);
		int x,y;
		for(int i=0;i<edge;i++){
			scanf("%d %d",&x,&y);
			grph[x].pb(y);
			grph[y].pb(x);
		}
		int i=1;
		while(i<=vert){
			if(lookup[i]==0)
				dfs(i,'W');
			if(flag==1)
				break;
			i++;
		}
		if(flag==0)
			printf("Scenario #%d:\nNo suspicious bugs found!\n",cnt);
		else 
			printf("Scenario #%d:\nSuspicious bugs found!\n",cnt);
	}
	return 0;
}
		
					
