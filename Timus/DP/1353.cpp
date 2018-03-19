#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll mod = int(1e9) + 7;
const int siz = int(1e5) + 5;

#define eb emplace_back
#define mp make_pair
#define OPEN 0

int dp[11][100];

int rec(int ind, int rem) {
    int ans = 0;
    if(ind == 1 && rem <= 9)
        return 1;
    else if(ind == 1 || rem > ind * 9)
        return 0;
    int &res = dp[ind][rem];
    if(res != -1)
        return res;
    else {
        for(int i = 0; i <= min(rem, 9); i++)
            ans += rec(ind - 1, rem - i);
        res = ans;
        return ans;
    }
}
int main() {
    if(int(OPEN))
        freopen("input.txt", "r", stdin);
    for(int i = 0; i < 11; i++)
        for(int j = 0; j < 100; j++)
            dp[i][j] = -1;
    int S;
    scanf("%d", &S);
    if(S == 1) {
        printf("10\n");
        return 0;
    }
    int ans = rec(9, S);
    printf("%d", ans);
    return 0;
}