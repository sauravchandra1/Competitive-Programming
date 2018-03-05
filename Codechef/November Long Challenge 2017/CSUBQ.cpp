
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll mod = 1e9 + 7;
const int siz = 1e6 + 5;
 
#define pb push_back
#define mp make_pair
 
struct node {
    ll left, right, range, lsmall, rsmall, mx;
}tree[4 * siz];
 
int arr[siz], L, R;
 
node merge(node a, node b) {
    node temp;
    if(a.left == a.range)
        temp.left = a.left + b.left;
    else
        temp.left = a.left;
    if(b.right == b.range)
        temp.right = b.right + a.right;
    else
        temp.right = b.right;
    temp.range = a.range + b.range;
    temp.mx = a.mx + b.mx + a.right * b.left - a.rsmall * b.lsmall;
    if(a.lsmall == a.range)
        temp.lsmall = a.lsmall + b.lsmall;
    else
        temp.lsmall = a.lsmall;
    if(b.rsmall == b.range)
        temp.rsmall = b.rsmall + a.rsmall;
    else
        temp.rsmall = b.rsmall;
    return temp;
}
 
void build(int low, int high, int pos) {
    if(low == high) {
        if(arr[low] >= L && arr[low] <= R) {
            tree[pos].left = 1;
            tree[pos].right = 1;
            tree[pos].mx = 1;
            tree[pos].range = 1;
            tree[pos].lsmall = 0;
            tree[pos].rsmall = 0;
        } else if(arr[low] < L) {
            tree[pos].left = 1;
            tree[pos].right = 1;
            tree[pos].mx = 0;
            tree[pos].range = 1;
            tree[pos].lsmall = 1;
            tree[pos].rsmall = 1;
        } else {
            tree[pos].left = 0;
            tree[pos].right = 0;
            tree[pos].mx = 0;
            tree[pos].range = 1;
            tree[pos].lsmall = 0;
            tree[pos].rsmall = 0;
        }
        return;
    }
    int mid = (low + high) / 2;
    int left = 2 * pos + 1;
    int right = 2 * pos + 2;
    build(low, mid, left);
    build(mid + 1, high, right);
    tree[pos] = merge(tree[left], tree[right]);
    return ;
}
 
void update(int start, int end, int low, int high, int pos, int val) {
    if(low > end || high < start)
        return ;
    if(low == high) {
        arr[low] = val;
        if(arr[low] >= L && arr[low] <= R) {
            tree[pos].left = 1;
            tree[pos].right = 1;
            tree[pos].mx = 1;
            tree[pos].range = 1;
            tree[pos].lsmall = 0;
            tree[pos].rsmall = 0;
        } else if(arr[low] < L) {
            tree[pos].left = 1;
            tree[pos].right = 1;
            tree[pos].mx = 0;
            tree[pos].range = 1;
            tree[pos].lsmall = 1;
            tree[pos].rsmall = 1;
        } else {
            tree[pos].left = 0;
            tree[pos].right = 0;
            tree[pos].mx = 0;
            tree[pos].range = 1;
            tree[pos].lsmall = 0;
            tree[pos].rsmall = 0;
        }
        return ;
    }
    int mid = (low + high) / 2;
    int left = 2 * pos + 1;
    int right = 2 * pos + 2;
    update(start, end, low, mid, left, val);
    update(start, end, mid + 1, high, right, val);
    tree[pos] = merge(tree[left], tree[right]);
    return ;
}
 
node query(int start, int end, int low, int high, int pos) {
    if(low > end || high < start) {
        node temp;
        temp.range = 0;
        temp.mx = 0;
        temp.left = 0;
        temp.right = 0;
        temp.lsmall = 0;
        temp.rsmall = 0;
        return temp;
    }
    if(low >= start && high <= end)
        return tree[pos];
    int mid = (low + high) / 2;
    int left = 2 * pos + 1;
    int right = 2 * pos + 2;
    node a = query(start, end, low, mid, left);
    node b = query(start, end, mid + 1, high, right);
    node c = merge(a, b);
    return c;
}
 
int main() {
    //freopen("input.txt", "r", stdin);
    int  N, Q, i, x, y, l, r;
    node temp;
    scanf("%d %d %d %d", &N, &Q, &L, &R);
    build(0, N - 1, 0);
    while(Q--) {
        scanf("%d", &i);
        if(i == 1) {
            scanf("%d %d", &x, &y);
            update(x - 1, x - 1, 0, N - 1, 0, y);
        } else {
            scanf("%d %d", &l, &r);
            temp = query(l - 1, r - 1, 0, N - 1, 0);
            printf("%lld\n", temp.mx);
        }
    }
    return 0;
} 
