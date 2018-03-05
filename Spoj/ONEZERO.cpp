#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const int siz = 1e5 + 5;

#define pb push_back
#define mp make_pair
#define psi pair < string , int >

int n;
string ans;

void bfs() {
    int a = 0;
    psi P;
    list < psi > Q;
    Q.pb(psi("1", 1));
    while(!Q.empty()) {
        P = Q.front();
        Q.pop_front();
        a = P.second;
        if(!(a % n)){
            ans = P.first;
            return ;
        }
        P.second %= n;
        Q.pb({P.first + "0", (P.second * 10)});
        Q.pb({P.first + "1", (P.second * 10 + 1)});
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        bfs();
        cout << ans << endl;
    }
    return 0;
}
