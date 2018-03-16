#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll mod = int(1e9) + 7;
const int siz = int(1e5) + 5;

#define eb emplace_back
#define mp make_pair
#define OPEN 0

ll dp[5][50];
ll B[5][50];
int n;

ll rec(int second_last, int last, int rem) {
    ll ans = 0;
    if(rem == 0)
        return 1;
    if(last == 2) {
        if (B[second_last][rem] != -1)
            return B[second_last][rem];
        if(second_last == 1) {
            ans = rec(2, 3, rem - 1);
            B[1][rem] = ans;
            return ans;
        }
        else {
            ans = rec(2, 1, rem - 1);
            B[3][rem] = ans;
            return ans;
        }
    }
    else {
        if (dp[last][rem] != -1)
            return dp[last][rem];
        if (last == 1) {
            if(rem > 1 && rem != n)
                ans = rec(1, 2, rem - 1) + rec(1, 3, rem - 1);
            else
                ans = rec(1, 3, rem - 1);
            dp[1][rem] = ans;
            return ans;
        } else if (last == 3) {
            if(rem > 1 && rem != n)
                ans = rec(3, 2, rem - 1) + rec(3, 1, rem - 1);
            else
                ans = rec(3, 1, rem - 1);
            dp[3][rem] = ans;
            return ans;
        }
    }
}

int main() {
    if(int(OPEN))
        freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0;i < 5; i++)
            for(int k = 0; k < 50; k++)
                dp[i][k] = -1;
    for(int i = 0; i < 5; i++)
            for(int k = 0; k < 50; k++)
                B[i][k] = -1;
    ll ans1 = rec(1, 3, n);
    ll ans2 = rec(3, 1, n);
    printf("%lld\n", ans1 + ans2);
    return 0;
}