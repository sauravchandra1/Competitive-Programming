#include <bits/stdc++.h>
using namespace std;

#define pb push_back

vector < int > V;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		V.clear();
		map < int , int > mp;
		int n, s, e, ans = 0, mx = 0;
		scanf("%d", &n);	
		for(int i = 0;i < n;i++) {
			scanf("%d %d", &s, &e);
			V.pb(s);
			V.pb(e);
			mp[s] = 1;
			mp[e] = 0;
		}
		sort(V.begin(), V.end());
		for(int i = 0;i < V.size();i++) {
			if(mp[ V[i] ] == 1)
				ans++;
			else if(mp[ V[i] ] == 0)
				ans--;
			if(ans > mx)
				mx = ans;
		}
		printf("%d\n", mx);
	}
	return 0;
}
