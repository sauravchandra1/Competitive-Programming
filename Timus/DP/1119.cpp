#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll mod = int(1e9) + 7;
const int siz = int(1e5) + 5;

#define eb emplace_back
#define mp make_pair
#define OPEN 0

int dig[1010][1010], n, m;
double dp[1010][1010];

double min(double a, double b) {
    return (a < b ? a : b);
}

double rec(int x, int y) {
    double ans;
    if(x > n || y > m)
        return 10000000.0;
    if(x == n && y == m)
        return 0.0;
    if(dp[x][y] != -1.0)
        return dp[x][y];
    if(dig[x + 1][y + 1])
        ans = rec(x + 1, y + 1) + sqrt(2);
    else
        ans = min(rec(x + 1, y), rec(x, y + 1)) + 1.0;
    dp[x][y] = ans;
    return ans;
}

int main() {
    if(int(OPEN))
        freopen("input.txt", "r", stdin);
    int x, y;
    scanf("%d %d", &n, &m);
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d %d", &x, &y);
        dig[x][y] = 1;
    }
    for(int i = 0; i <= 1000; i++)
        for(int j = 0; j <= 1000; j++)
            dp[i][j] = -1.0;
    double ans = rec(0, 0) * 100;
    int result = round(ans);
    printf("%d", result);
    return 0;
}