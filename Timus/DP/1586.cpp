#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll mod = int(1e9) + 9;
const int siz = 200;

#define eb emplace_back
#define mp make_pair
#define OPEN 0

ll prime[siz], ind, dp[2][siz];
vector < int > vec[siz];

void find_prime() {
    int flag = 0;
    for (int i = 101; i <= 1000; i++) {
        flag = 0;
        for (int j = 2; j <= sqrt(i); j++) {
            if (!(i % j)) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            int x, y;
            x = y = i;
            x /= 10;
            y /= 100;
            if (y * 10 == x)
                ;
            else {
                prime[ind] = i;
                ind++;
            }
        }
    }
}

int main() {
    if (int(OPEN))
        freopen ("input.txt", "r", stdin);
    find_prime();
    ll temp;
    ll ans = 0;
    for (int i = 0; i < siz; i++)
        dp[0][i] = dp[1][i] = 0;
    for (int i = 0; i < ind; i++) {
        temp = prime[i];
        vec[temp / 10].eb(temp);
    }
    int n;
    scanf("%d", &n);
    if (n == 3)
        printf("143\n");
    else {
        int flag = 0;
        for (int i = 0; i < ind; i++)
            dp[1][prime[i] % 100]++;
        for (int i = 4; i <= n; i++) {
            for (int j = 11; j <= 99; j++) {
                if (dp[1 - flag][j]) {
                    for (int k = 0; k < vec[j].size(); k++) {
                        temp = vec[j][k];
                        dp[flag][temp % 100] = (dp[1 - flag][j] % mod + dp[flag][temp % 100] % mod) % mod;
                    }
                }
            }
            ans = 0;
            for (int t = 11; t <= 99; t++)
                ans = (ans % mod + dp[flag][t] % mod) % mod;
            flag = 1 - flag;
            for (int u = 0; u < siz; u++)
                dp[flag][u] = 0;
        }
        printf("%lld\n", ans);
    }
    return 0;
}