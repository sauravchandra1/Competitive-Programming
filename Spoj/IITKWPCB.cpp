#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const int siz = 1e5 + 5;

#define pb push_back
#define mp make_pair

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while(t--) {
        ll n;
        cin >> n;
        if(n % 2)
            cout << n/2 << endl;
        else {
            if(n/2 % 2)
                cout << n/2 - 2 << endl;
            else
                cout << n/2 - 1 << endl;
        }
    }
    return 0;
}
