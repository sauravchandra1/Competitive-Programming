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
    ll x1, y1, x2, y2, R;
    cin >> R >> x1 >> y1 >> x2 >> y2;
    if((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) >= R * R) {
        cout << x1 << " " << y1 << " " << R  << endl;
        return 0;
    }
    ll diff1 = x2 - x1;
    ll diff2 = y2 - y1;
    double dist = sqrt(diff1 * diff1 + diff2 * diff2);
    double r = (R + dist) / 2.0;
    if(!dist) {
        if(x1 < 0)
            printf("%lf %I64d %lf",x1 - R / 2.0, y1, r);
        else
            printf("%lf %I64d %lf",x1 + R / 2.0, y1, r);
        return 0;
    }
    double x = ((x1 - x2) / dist ) * r + x2;
    double y = ((y1 - y2) / dist ) * r + y2;
    printf("%0.16lf %0.16lf %0.16lf\n", x, y, r);
    return 0;
}
