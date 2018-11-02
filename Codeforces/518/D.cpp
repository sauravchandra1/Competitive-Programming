#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define A 200
#define MOD 998244353
long long dp[N + 10][A + 10][2];
int main() {
    int n;
    cin >> n;
    long long arr[N + 10];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (arr[0] == -1) 
    	for (int i = 1; i <= A; i++)
    		dp[0][i][0] = 1;
    else
    	dp[0][arr[0]][0] = 1;
    for (int i = 1; i < n; i++) {
    	if (arr[i] == -1) {
    		for (int j = 2; j <= A; j++)
    			dp[i][j][0] = (dp[i][j - 1][0] % MOD + dp[i - 1][j - 1][0] % MOD + dp[i - 1][j - 1][1] % MOD) % MOD;
    		dp[i][A][1] = dp[i - 1][A][1];
    		for (int j = A - 1; j >= 1; j--) 
    			dp[i][j][1] = (dp[i][j + 1][1] % MOD + dp[i - 1][j][1] % MOD) % MOD;
    		for (int j = A; j >= 1; j--)
    			dp[i][j][1] = (dp[i][j][1] % MOD + dp[i - 1][j][0] % MOD) % MOD; 
    	}
    	else {
    		int a = arr[i];
    		for (int j = 1; j <= a - 1; j++) 
    			dp[i][a][0] = (dp[i][a][0] % MOD + 
    						dp[i - 1][j][0] % MOD + dp[i - 1][j][1] % MOD) % MOD;
    		dp[i][a][1] = dp[i - 1][a][0];
    		for (int j = a; j <= A; j++) 
    			dp[i][a][1] = (dp[i][a][1] % MOD + dp[i - 1][j][1] % MOD) % MOD;
  	  	}
    }
    long long ans = 0;
   	if (arr[n - 1] == -1) 
   		for (int i = 1; i <= A; i++)
   			ans = (ans % MOD + dp[n - 1][i][1] % MOD) % MOD;
   	else
   		ans = dp[n - 1][arr[n - 1]][1];
   	cout << ans << endl;
    return 0;
}
