#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll mod = int(1e9) + 7;
const int siz = int(1e5) + 5;

#define eb emplace_back
#define mp make_pair
#define OPEN 0

ll S1[siz], S2[siz], n, m, M, M2;

ll power(ll a, ll m) {
    if(m == 0)
        return 1;
    ll temp;
    temp = power(a, m / 2) % mod;
    if(m & 1)
        temp = ((temp * temp) % mod * a % mod) % mod;
    else
        temp = (temp * temp) % mod;
    return temp;
}

ll find(int ind) {
    if(ind == n)
        return 0;
    else if(S1[ind] != 0 && S2[ind] != 0 && S1[ind] > S2[ind])
        return 1;
    else if(S1[ind] != 0 && S2[ind] != 0 && S1[ind] < S2[ind])
        return 0;
    else if(S1[ind] != 0 && S2[ind] != 0 && S1[ind] == S2[ind])
        return find(ind + 1);
    else if(S1[ind] == 0 && S2[ind] != 0)
        return ((((m - S2[ind]) % mod) * (M % mod) % mod + (find(ind + 1) % mod) * (M % mod) % mod)) % mod;
    else if(S1[ind] != 0 && S2[ind] == 0)
        return ((((S1[ind] - 1) % mod) * (M % mod) % mod + (find(ind + 1) % mod) * (M % mod) % mod)) % mod;
    else if(S1[ind] == 0 && S2[ind] == 0)
        return ((((m - 1) % mod) * (M2 % mod) % mod + (find(ind + 1) % mod) * (M % mod) % mod)) % mod;
}

int main() {
    if(int(OPEN))
        freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> S1[i];
    for(int i = 0; i < n; i++)
        cin >> S2[i];
    M = power(m, mod - 2);
    M2 = power(2 * m, mod - 2);
    ll ans = find(0);
    cout << ans << endl;
    return 0;
}

