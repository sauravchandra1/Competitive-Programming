#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const ll mod = 1e9 + 7;
const int siz = 1e5 + 5;
const int lim = 12;
const int inf = 9999999;

#define eb emplace_back
#define mp make_pair
#define OPEN 0

int main() {
	if (OPEN) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	int test;
	scanf("%d", &test);
	while (test--) {
		int X, Y;
		scanf("%d %d", &X, &Y);
		pii origin;
		cin >> origin.first >> origin.second;
		vector < pii > pos;
		int x, y, n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			pos.eb(mp(x, y));
		}
		vector < vector < int > > grid;
		grid.resize(n + 1, vector < int > (n + 1));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) { 
				if (i == j)
					grid[i][j] = 0;
				else
					grid[i][j] = abs(pos[i - 1].first - pos[j - 1].first) + abs(pos[i - 1].second - pos[j - 1].second);
			}
		}
		vector < vector < pii > > dp;
		dp.resize((1<<lim), vector < pii > (lim)); 
		for (int i = 0; i < (1<<lim); i++) 
			for (int j = 0; j < lim; j++)
				dp[i][j].first = dp[i][j].second = inf;
		int new_mask, end, ans;
		for (int mask = 1; mask < (1<<n); mask++) {
			for (int ind = 0; ind < n; ind++) {
				if ((mask & (1<<ind)) == 0)
					continue;
				new_mask = mask ^ (1<<ind);
				if (new_mask == 0) {
					dp[mask][ind + 1].first = 0;
					dp[mask][ind + 1].second = ind + 1;
				}
				else {
					for (int idx = 0; idx < n; idx++) {
						if ((new_mask & (1<<idx)) == 0)
							continue;
						ans = grid[ind + 1][idx + 1] + dp[new_mask][idx + 1].first;    
						if (ans < dp[mask][ind + 1].first) {
							dp[mask][ind + 1].first = ans;
							dp[mask][ind + 1].second = dp[new_mask][idx + 1].second;
						}
					}
				}
			}
		}
		int dist1, dist2;
		ans = inf;
		for (int i = 1; i <= n; i++) {
			end = dp[(1<<n) - 1][i].second;
			dist1 = abs(origin.first - pos[i - 1].first) + abs(origin.second - pos[i - 1].second);
			dist2 = abs(origin.first - pos[end - 1].first) + abs(origin.second - pos[end - 1].second);
			ans = min(ans, dp[(1<<n) - 1][i].first + dist1 + dist2);
		}
		printf("The shortest path has length %d\n", ans);
	}
	return 0;
}
