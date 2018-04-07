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
    int n;
    scanf("%d", &n);
    int dp[56];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i <= 55; i++)
        dp[i] = dp[i - 1] + dp[i - 3] + 1;
    printf("%d\n", dp[n]);
    return 0;
}