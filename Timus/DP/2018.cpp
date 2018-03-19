#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll mod = int(1e9) + 7;
const int siz = int(5e4) + 5;

#define eb emplace_back
#define mp make_pair
#define OPEN 0

int n, len[2];
ll dp[siz][2];

int main() {
    if(int(OPEN))
        freopen("input.txt", "r", stdin);
    scanf("%d %d %d", &n, &len[0], &len[1]);
    dp[0][0] = dp[0][1] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= 1; j++)
            for(int k = 1; k <= min(i, len[j]); k++)
                dp[i][j] = (dp[i][j] % mod + dp[i - k][1 - j] % mod) % mod;
    printf("%lld\n", (dp[n][0] % mod + dp[n][1] % mod) % mod);
    return 0;
}