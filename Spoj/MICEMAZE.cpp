#include <bits/stdc++.h>
using namespace std;

#define N 10004
#define INF 1000000009
#define pii pair< int, int >

vector< pii > G[N];
int d[N], f[N];

int main(){
	int n, exit, time, e, u, v, w, start, sz, vi, wi, ui, i, j, ans = 0;
	scanf("%d %d %d %d", &n, &exit, &time, &e);
	for(j = 1;j <= e;j++) {
		scanf("%d%d%d",&u, &v, &w);
		G[u].push_back(pii(w, v));
	}
	for(i = 1;i <= n;i++) {
		priority_queue< pii, vector< pii >, greater< pii > > Q;
		start = i;
		Q.push(pii(0, start));
		for(j = 1;j <= n;j++) {
			d[j] = INF;
			f[j] = 0;
		}
		d[start] = 0;
		while(!Q.empty()) {
			ui = Q.top().second;
			wi = Q.top().first;
			Q.pop();
			if(f[ui]) continue;
			sz = G[ui].size();
			for(j = 0;j < sz;j++) {
				vi = G[ui][j].second;
				w = G[ui][j].first;
				if(!f[vi] && d[ui] + w < d[vi]) {
					d[vi] = d[ui] + w;
					Q.push(pii(d[vi],vi));
				}
			}
			f[ui] = 1;
			if(ui == exit) break;
		}
		if(d[exit] <= time)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}
					
				
			
	
			
