#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll mod = 1e9 + 7;
const int siz = 1e5 + 5;
 
#define pb push_back
#define mp make_pair
 
struct poly{
    ll a0, a1, a2, a3;
} arr[siz];
 
int ind[siz], ind2, n;
ll ans, mn;
 
void find_ind(ll l, ll r) {
    mn = -1;
    for(int j = 0;j < n;j++) {
        ans = arr[j].a0 + (arr[j].a1 * l) + (arr[j].a2 * l * l) +
              (arr[j].a3 * l * l * l);
        if (mn == -1 || ans < mn) {
            mn = ans;
            ind2 = j;
        }
    }
    ind[l] = ind2;
    mn = -1;
    for(int j = 0;j < n;j++) {
        ans = arr[j].a0 + (arr[j].a1 * r) + (arr[j].a2 * r * r) +
              (arr[j].a3 * r * r * r);
        if (mn == -1 || ans < mn) {
            mn = ans;
            ind2 = j;
        }
    }
    ind[r] = ind2;
    if(ind[l] == ind[r]) {
        for (ll i = l + 1; i < r; i++)
            ind[i] = ind[l];
        return;
    }
    ll mid = (l + r)/2;
    find_ind(l, mid);
    find_ind(mid + 1, r);
}
 
int main() {
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--) {
        int q;
        ll query = 0, ind1 = 0;
        ll l = 250, r = 100000;
        scanf("%d", &n);
        for(int i = 0;i < n;i++)
            scanf("%lld %lld %lld %lld", &arr[i].a0, &arr[i].a1, &arr[i].a2, &arr[i].a3);
        find_ind(l, r);
        scanf("%d", &q);
        for(int i = 0;i < q;i++) {
            scanf("%lld", &query);
            mn = -1;
            if(query < 250) {
                for(int j = 0;j < n;j++) {
                    ans = arr[j].a0 + (arr[j].a1 * query) + (arr[j].a2 * query * query) +
                          (arr[j].a3 * query * query * query);
                    if (mn == -1 || ans < mn)
                        mn = ans;
                }
            } else {
                ind1 = ind[query];
               mn =  arr[ind1].a0 + (arr[ind1].a1 * query) + (arr[ind1].a2 * query * query) +
                     (arr[ind1].a3 * query * query * query);
            }
            printf("%lld\n", mn);
        }
    }
    return 0;
} 
