#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll mod = int(1e9) + 7;
const int siz = 505;

#define eb emplace_back
#define mp make_pair
#define OPEN 0

int dp[siz][siz], arr[siz], N, K;

int rec(int ind, int rem) {
    if(N - ind < rem)
        return 99999999;
    if(N - ind == rem)
        return 0;
    int &res = dp[ind][rem];
    if(res != -1)
        return res;
    else if(rem == 1) {
        int one = 0, zero = 0;
        for(int i = ind; i < N; i++) {
            if (arr[i] == 1)
                one++;
            else
                zero++;
        }
        res = one * zero;
        return res;
    }
    else {
        int ans = 0, one = 0, zero = 0, mn = 99999999;
        if(arr[ind] == 1)
            one++;
        else
            zero++;
        for(int i = ind + 1; i < N; i++) {
            ans = rec(i, rem - 1) + (one * zero);
            mn = min(mn, ans);
            if(arr[i] == 1)
                one++;
            else
                zero++;
        }
        res = mn;
        return mn;
    }
}

int main() {
    if(int(OPEN))
        freopen("input.txt", "r", stdin);
    for(int i = 0; i < siz; i++)
        for(int j = 0; j < siz; j++)
            dp[i][j] = -1;
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    int ans = rec(0, K);
    printf("%d\n", ans);
    return 0;
}