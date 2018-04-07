#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll mod = int(1e9) + 7;
const int siz = 505;

#define eb emplace_back
#define mp make_pair
#define OPEN 0

int dp[siz][siz], arr[siz];

int main() {
    if(int(OPEN))
        freopen("input.txt", "r", stdin);
    int N, K, one = 0, zero = 0;
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);
    for (int i = 1; i <= N; i++) {
        if(arr[i])
            one++;
        else
            zero++;
        dp[i][1] = one * zero;
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= K; j++) {
            if(j > i)
                break;
            one = 0, zero = 0;
            dp[i][j] = 9999999;
            for (int k = i; k >= j; k--) {
                if(arr[k])
                    one++;
                else
                    zero++;
                dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + one * zero);
            }
        }
    }
    printf("%d\n", dp[N][K]);
    return 0;
}