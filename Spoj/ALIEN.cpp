#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const int siz = 1e6 + 6;

#define pb push_back
#define mp make_pair

int arr[siz];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while(t--) {
        int n , sum, cnt = 0, S = 0, mx = -1, ind = 0, a_sum = 0;
        scanf("%d %d", &n, &sum);
        for(int i = 0;i < n;i++)
            scanf("%d", &arr[i]);
        for(int i = 0;i < n;i++) {
            if((S + arr[i]) <= sum) {
                S += arr[i];
                cnt++;
            }
            else {
                S += arr[i];
                cnt++;
                while(S > sum) {
                    S -= arr[ind];
                    ind++;
                    cnt--;
                }
            }
            if(mx < cnt) {
                mx = cnt;
                a_sum = S;
            }
            else if(mx == cnt) {
                if(a_sum > S)
                    a_sum = S;
            }
        }
        printf("%d %d\n", a_sum, mx);
    }
    return 0;
}
