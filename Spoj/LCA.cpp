#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const int siz = 1e5 + 5;

#define N 1003
#define root 1
#define pb push_back
#define mp make_pair

const int LN = 12;
vector< int > u[N];
int prnt[LN][N], depth[N];

void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void dfs(int cur, int dep, int prev) {
    prnt[0][cur] = prev;
    depth[cur] = dep;
    for(int i = 0;i < u[cur].size();i++)
        dfs(u[cur][i], dep + 1, cur);
}

int LCA(int a, int b) {
    int ad, bd, dis;
    ad = depth[a];
    bd = depth[b];
    if(ad > bd) {
        swap(&ad, &bd);
        swap(&a, &b);
    }
    dis = bd - ad;
    for(int i =  LN;i >= 0;i--)
        if((dis >> i) & 1)
            b = prnt[i][b];
    if(a == b)
        return a;
    for(int i = LN - 1;i >= 0;i--) {
        if (prnt[i][a] != prnt[i][b]) {
            a = prnt[i][a];
            b = prnt[i][b];
        }
    }
    return prnt[0][a];
}

int main() {
//#ifndef ONLINE_JUDGE
  //  freopen("input.txt", "r", stdin);
//#endif
    int t, cnt = 0;
    scanf("%d", &t);
    while(t--) {
        cnt++;
        for(int i = 0;i < N;i++) {
            u[i].clear();
            depth[i] = 0;
            for(int j = 0;j < LN;j++)
                prnt[j][i] = -1;
        }
        int nodes, conn, x, q, a, b;
        scanf("%d", &nodes);
        for(int i = 1;i <= nodes;i++) {
            scanf("%d", &conn);
            while(conn--) {
                scanf("%d", &x);
                u[i].pb(x);
            }
        }
        dfs(root, 0, -1);
        for(int i = 1;i < LN;i++)
            for(int j = 1;j <= nodes;j++)
                if(prnt[i - 1][j] != -1)
                    prnt[i][j] = prnt[i - 1][prnt[i - 1][j]];
        scanf("%d", &q);
        printf("Case %d:\n", cnt);
        while(q--) {
            scanf("%d %d", &a, &b);
            printf("%d\n", LCA(a, b));
        }
    }
    return 0;
}