#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll mod = int(1e9) + 7;
const int siz = 110;

#define eb emplace_back
#define mp make_pair
#define OPEN 0

int N, matrix[siz][siz], sum[siz][siz], max_sum, ans;

int main() {
    if(int(OPEN))
        freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &matrix[i][j]);
    for(int i = 0; i < N; i++)
        for(int j = 1; j <= N; j++)
            sum[i][j] = sum[i][j - 1] + matrix[i][j - 1];
    ans = matrix[0][0];
    for(int mat_siz = 1; mat_siz <= N; mat_siz++) {
        for(int j = mat_siz; j <= N; j++) {
            max_sum = sum[0][j] - sum[0][j - mat_siz];
            for(int i = 1; i < N; i++) {
                max_sum = max(sum[i][j] - sum[i][j - mat_siz], max_sum + sum[i][j] - sum[i][j - mat_siz]);
                ans = max(ans, max_sum);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
