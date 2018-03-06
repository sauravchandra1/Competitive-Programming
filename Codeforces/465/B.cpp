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
    int x = 0, y = 0;
    int len = 0;
    cin >> len;
    string S;
    cin >> S;
    char last;
    int ans = 0;
    for(int i = 0; i < len; i++) {
        if(x == y && x != 0) {
            if(S[i] == last)
                ans++;
        }
        if(S[i] == 'U') {
            y++;
            last = 'U';
        }
        else {
            x++;
            last = 'R';
        }
    }
    printf("%d\n", ans);
    return 0;
}
