#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int l, n, arr[N];
int dp[N][N];
int main() {
	while (true) {
		scanf("%d", &l);
		if (l == 0)
			break;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) 
			scanf("%d", &arr[i]);
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++)
				dp[i][j] = 0;
		arr[0] = 0;
		arr[n + 1] = l;
		for (int len = 1; len <= n; len++) {
			for (int siz = 0; siz <= n - len; siz++) {
				dp[siz][siz + len + 1] = INT_MAX;
				for (int k = siz + 1; k <= len + siz; k++) {
					dp[siz][siz + len + 1] = min(dp[siz][siz + len + 1], dp[siz][k] + dp[k][siz + len + 1] + (arr[siz + len + 1] - arr[siz]));
				}
			}
		}
		printf("The minimum cutting is %d.\n", dp[0][n + 1]);
	}
	return 0;
}
