#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const int siz = 1e5 + 5;

#define pb push_back
#define mp make_pair

int vis[siz];
ll dp[siz];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif
	int t;
	scanf("%d", &t);
	while(t--) {
		memset(vis, -1, sizeof vis);
		string S;
		cin >> S;
		dp[0] = 1;
		for(unsigned int i = 0;i < S.size();i++) {
			dp[i + 1] = (dp[i] % mod * 2 % mod) % mod;
			if(vis[int(S[i])] != -1) 
				dp[i + 1] = (dp[i + 1] % mod - dp[vis[int(S[i])]] % mod + mod) % mod;
			vis[int(S[i])] = i;
		}
		printf("%lld\n", dp[S.size()]);
	}
	return 0;
}
