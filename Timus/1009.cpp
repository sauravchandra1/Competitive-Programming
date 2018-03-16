#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll mod = int(1e9) + 7;
const int siz = 20;

#define eb emplace_back
#define mp make_pair
#define OPEN 0

ll N, K, dp[siz][2];

ll rec(ll ind, ll zero) {
    ll ans;
    if(ind == 1)
        return (zero == 1 ? (K - 1) : K);
    ll &res = dp[ind][zero];
    if(res != -1)
        return res;
    else {
        if(zero == 1)
            ans = (K - 1) * rec(ind - 1, 0);
        else
            ans = rec(ind - 1, 1) + (K - 1) * rec(ind - 1, 0);
        res = ans;
        return ans;
    }
}

int main() {
    if(int(OPEN))
        freopen("input.txt", "r", stdin);
    for(int i = 0; i < siz; i++)
        for(int j = 0; j < 2; j++)
            dp[i][j] = -1;
    scanf("%lld %lld", &N, &K);
    ll ans = (K - 1) * rec(N - 1, 0);
    printf("%lld\n", ans);
    return 0;
}