#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define N 1100
long long dp[N][2 * N][2][2];
int main() {
	long long n, k;
	cin >> n >> k;
	dp[1][1][0][0] = dp[1][1][1][1] = 1;
	dp[1][2][0][1] = dp[1][2][1][0] = 1;
	for (int i = 2; i <= n; i++) {
		for (int new_u = 0; new_u < 2; new_u++) {
			for (int new_d = 0; new_d < 2; new_d++) {
				for (int part = 1; part <= k; part++) {
					if (new_u == 0 && new_d == 0) {
						dp[i][part][0][0] = (dp[i][part][0][0] + dp[i - 1][part][0][0] + dp[i - 1][part][0][1] + dp[i - 1][part][1][0]) % MOD;
						dp[i][part + 1][0][0] = (dp[i][part + 1][0][0] + dp[i - 1][part][1][1]) % MOD;
					}
					else if (new_u == 0 && new_d == 1) {
						dp[i][part][0][1] = (dp[i][part][0][1] + dp[i - 1][part][0][1]) % MOD;
						dp[i][part + 1][0][1] = (dp[i][part + 1][0][1] + dp[i - 1][part][0][0] + dp[i - 1][part][1][1]) % MOD;
						dp[i][part + 2][0][1] = (dp[i][part + 2][0][1] + dp[i - 1][part][1][0]) % MOD;
					}
					else if (new_u == 1 && new_d == 0) {
						dp[i][part][1][0] = (dp[i][part][1][0] + dp[i - 1][part][1][0]) % MOD;
						dp[i][part + 1][1][0] = (dp[i][part + 1][1][0] + dp[i - 1][part][0][0] + dp[i - 1][part][1][1]) % MOD;
						dp[i][part + 2][1][0] = (dp[i][part + 2][1][0] + dp[i - 1][part][0][1]) % MOD;
					}
					else if (new_u == 1 && new_d == 1) {
						dp[i][part][1][1] = (dp[i][part][1][1] + dp[i - 1][part][0][0] + dp[i - 1][part][0][1] + dp[i - 1][part][1][0]) % MOD;
						dp[i][part + 1][1][1] = (dp[i][part + 1][1][1] + dp[i - 1][part][0][0]) % MOD;
					}
				}
			}
		}
	}
	cout << (dp[n][k][0][0] + dp[n][k][1][1] + dp[n][k][0][1] + dp[n][k][1][0]) % MOD << endl;
	return 0;
}