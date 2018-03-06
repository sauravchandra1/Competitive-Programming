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
    int rem = 0;
    int ans = 0;
    for(int i = 1; i < n; i++) {
        rem = n - i;
        if(!(rem % i))
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}
