#include <bits/stdc++.h>
using namespace std;

#define N 10004

typedef long long ll;
ll arr[N];

struct data{
	ll s;
	ll e;
}upt[N];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		for(int i = 0;i < N;i++)
			upt[i].s = upt[i].e = 0;
		int n, u, l, r, val, q, ind;
		ll temp = 0;
		scanf("%d %d", &n, &u);
		for(int i = 0;i < u;i++) {
			scanf("%d %d %d", &l, &r, &val);
			upt[l].s += val;
			upt[r].e += val;
		}
		for(int i = 0;i < n;i++) {
			temp += upt[i].s;
			arr[i] = temp;
			temp -= upt[i].e;
		}
		scanf("%d", &q);	
		for(int i = 0;i < q;i++) {
			scanf("%d", &ind);
			printf("%lld\n", arr[ind]);
		}
	}
	return 0;
}
		
