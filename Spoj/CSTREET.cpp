#include <bits/stdc++.h>
using namespace std;

struct edge{
	int v,w;
};

bool operator <(edge a,edge b){
	return a.w > b.w;
}

void prim(vector< edge > graph[],int N,int p) {
	bool visited[N + 1];
	int i;
	memset(visited,false,sizeof visited);
	priority_queue< edge > q;
	queue< edge > mst;
	for(i = 1;i <= N;i++){
		if(graph[i].size() > 0){
			q.push((edge){i,0});
			break;
		}
	}
	while(!q.empty()){
		edge p = q.top();
		q.pop();	
		if(!visited[p.v]){
			visited[p.v] = true;
			mst.push(p);
			for(i = 0;i < graph[p.v].size();i++){
				edge k = graph[p.v][i];
				if(!visited[k.v])
					q.push(k);
			}
		}
	}
	int sum=0;
	while(!mst.empty()){
		sum += mst.front().w;
		mst.pop();
	}
	sum *= p;
	printf("%d\n",sum);
}
		
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int u,v,w,p,N,M;
		scanf("%d %d %d",&p,&N,&M);
		vector<edge> graph[N+1];
		for(int i = 0;i < M;i++){
			scanf("%d %d %d",&u,&v,&w);
			graph[u].push_back((edge){v,w});
			graph[v].push_back((edge){u,w});
		}
		prim(graph,N,p);
	}
	return 0;
}
			
