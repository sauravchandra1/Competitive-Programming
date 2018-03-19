#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll mod = int(1e9) + 7;
const int siz = int(1e5) + 5;

#define eb emplace_back
#define mp make_pair
#define OPEN 0

int main() {
    if(int(OPEN))
        freopen("input.txt", "r", stdin);
    ll N, K;
    scanf("%lld %lld", &N, &K);
    ll dp[20][2], temp = 0;
    for(int i = 0; i < 20; i++)
        dp[i][0] = dp[i][1] = 0;
    dp[0][0] = dp[0][1] = dp[1][0] = dp[1][1] = 1;
    for(int i = 2; i <= N; i++) {
        temp = 0;
        dp[i][0] = dp[i - 1][1] * (K - 1);
        dp[i][1] = 1;
        for(int j = 2; j <= i - 1; j++)
            dp[i][1] += dp[j][0];
        for(int j = 1; j <= i - 1; j++)
            temp += dp[j][1];
        dp[i][1] += temp * (K - 2);
    }
    printf("%lld\n", dp[N][0] + dp[N][1] * (K - 1));
    return 0;
}