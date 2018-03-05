#include <bits/stdc++.h>
using namespace std;

int dp[20][100];

int solve(int n, int k) {
	if(n == 0)
		return 0;
	if(k == 0)
		return 1;
	if(dp[n][k] != - 1)
		return dp[n][k];
	else {
		int sum = 0;
		for(int i = k;i >= 0;i--)
			if(i + n - 1 >= k)
				sum += solve(n - 1, i);
		dp[n][k] = sum;
		return dp[n][k];
	}
}
 
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		memset(dp, -1, sizeof dp);
		int n, k, ans = 0;
		scanf("%d %d", &n, &k);
		ans = solve(n, k);
		printf("%d\n", ans);
	}
	return 0;
}
		
