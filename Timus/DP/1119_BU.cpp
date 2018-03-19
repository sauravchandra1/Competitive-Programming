#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll mod = int(1e9) + 7;
const int siz = int(1e3) + 5;

#define eb emplace_back
#define mp make_pair
#define OPEN 0

double dp[siz][siz];
int dig[siz][siz];

int main() {
    if(int(OPEN))
        freopen("input.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    int k;
    scanf("%d", &k);
    int x, y;
    for(int i = 0; i < k; i++) {
        scanf("%d %d", &x, &y);
        dig[x][y] = 1;
    }
    double val = 0.0;
    for(int i = 0; i <= max(n, m); i++) {
        dp[i][0] = dp[0][i] = val;
        val = val + 1.0;
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(dig[j][i])
                dp[j][i] = dp[j - 1][i - 1] + sqrt(2);
            else
                dp[j][i] = min(dp[j - 1][i], dp[j][i - 1]) + 1.0;
        }
    }
    int result = int(round(dp[n][m] * 100));
    printf("%d\n", result);
    return 0;
}