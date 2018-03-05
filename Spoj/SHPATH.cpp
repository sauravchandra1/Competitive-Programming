#include <bits/stdc++.h>
using namespace std;

#define N 10004
#define INF 1000000009
#define pii pair< int, int >
#define psi pair< string, int >

map< string, int > M;
map< string, int > :: iterator it;
vector< pii > G[N];
int d[N], f[N];

int main(){
	int t, n, e, i, j, q, start, end, v, w, wi, vi, ui, sz;
	char city[20];
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(i = 1;i <= n;i++) {
			scanf("%s%d", city, &e);
			M.insert(psi(city,i));
			for(int j = 1;j <= e;j++) {
				scanf("%d%d", &v, &w);
				G[i].push_back(pii(w, v));
			}
		}
		scanf("%d", &q);
		for(i = 0;i < q;i++){
			scanf("%s", city);
			it = M.find(city);
			start = (*it).second;
			scanf("%s", city);
			it = M.find(city);
			end = (*it).second;
			priority_queue< pii, vector< pii >, greater< pii > > Q;
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
				if(ui == end) break;
			}
			printf("%d\n", d[end]);
		}
		for(i = 1;i <= n;i++) G[i].clear();
		M.clear();
	}
	return 0;
}
					
				
			
	
			
