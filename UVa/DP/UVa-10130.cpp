#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const ll mod = 1e9 + 7;
const int MAX_N = 1e3 + 3;
const int MAX_G = 33;

#define eb emplace_back
#define mp make_pair
#define OPEN 0

vector < pii > obj;
vector < int > gro;

int dp[MAX_N][MAX_G];

int main() {
	if (OPEN) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	int test;
	scanf("%d", &test);
	while (test--) {
		obj.clear();
		gro.clear();
		int n;
		scanf("%d", &n);
		int x, y;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			obj.eb(mp(x, y));
		}
		int g;
		scanf("%d", &g);
		for (int i = 0; i < g; i++) {
			scanf("%d", &x);
			gro.eb(x);
		}
		int cap, ans = 0;
		for (int k = 0; k < g; k++) {
			cap = gro[k];
			for (int l = 0; l < MAX_G; l++)
				dp[0][l] = 0;;
			for (int l = 0; l <= n; l++) 
				dp[l][0] = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j <= cap; j++) 
					dp[i][j] = (obj[i - 1].second <= j) ? max(obj[i - 1].first + dp[i - 1][j - obj[i - 1].second], dp[i - 1][j]) : dp[i - 1][j];
			}
			ans += dp[n][cap];	
		}
		printf("%d\n", ans);
	}
	return 0;
}
