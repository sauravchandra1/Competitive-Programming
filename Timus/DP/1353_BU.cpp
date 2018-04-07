#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll mod = int(1e9) + 7;
const int siz = 90;

#define eb emplace_back
#define mp make_pair
#define OPEN 0

ll dp[siz][2];

int main() {
    if(int(OPEN))
        freopen("input.txt", "r", stdin);
    for(int i = 0; i <= 9; i++)
        dp[i][0] = 1;
    int S;
    scanf("%d", &S);
    if(S == 1) {
        printf("10\n");
        return 0;
    }
    int flag = 1;
    for(int i = 2; i <= 9; i++) {
        for (int j = 0; j <= 81; j++) {
            dp[j][flag] = 0;
            for (int k = 0; k <= 9; k++) {
                if (j >= k)
                    dp[j][flag] += dp[j - k][1 - flag];
            }
        }
        flag = 1 - flag;
    }
    printf("%lld\n", dp[S][1 - flag]);
    return 0;
}