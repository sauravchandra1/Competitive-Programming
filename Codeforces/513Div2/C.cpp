#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector < long long > a(n), b(m);
    for (int i = 0; i < n; i++)
    	cin >> a[i];
    for (int j = 0; j < m; j++)
    	cin >> b[j];
    long long x;
    cin >> x;
    vector < long long > sum_a(n + 1, INT_MAX), sum_b(m + 1, INT_MAX);
    long long cnt;
    for (int i = 0; i < n; i++) {
    	cnt = 0;
    	for (int j = i; j < n; j++) {
    		cnt += a[j];
            sum_a[j - i + 1] = min(sum_a[j - i + 1], cnt);
    	}
    }
    for (int i = 0; i < m; i++) {
        cnt = 0;
        for (int j = i; j < m; j++) {
            cnt += b[j];
            sum_b[j - i + 1] = min(sum_b[j - i + 1], cnt);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (sum_a[i] * sum_b[j] <= x)
                ans = max(ans, i * j);
        }
    }
    cout << ans << endl;
    return 0;
}