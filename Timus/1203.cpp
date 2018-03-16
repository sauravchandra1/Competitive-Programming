#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll mod = int(1e9) + 7;
const int siz = int(1e5) + 5;

#define eb emplace_back
#define mp make_pair
#define OPEN 0

struct data {
    int start;
    int end;
}arr[siz];

bool cmp(data a, data b) {
    if(a.end == b.end)
        return (a.start < b.start);
    else
        return (a.end < b.end);
}

int main() {
    if(int(OPEN))
        freopen("input.txt", "r", stdin);
    int n, last = -1, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);
    sort(arr, arr + n, cmp);
    for(int i = 0; i < n; i++) {
        if(arr[i].start > last) {
            ans++;
            last = arr[i].end;
        }
    }
    printf("%d\n", ans);
    return 0;
}