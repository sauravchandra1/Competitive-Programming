#include <bits/stdc++.h>
using namespace std;

#define MN 300000
#define MX 15000000

int a[MN + 5];
int u[MX + 5];
int p[MX + 5];
int s[MX + 5];
int pn;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x; 
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n, i, j, g, x, ans = 0;
	for (int i = 2; i <= MX; i++) {
		if (!u[i])
			for (int j = i; j <= MX; j += i)
				u[j] = i;
	}
	// for (int i = 1; i <= MX; i++)
	// 	cout << i << " -> " << u[i] << endl;
	// for (int i = 1; i <= pn; i++)
	// 	cout << p[i] << " ";
	scanf("%d", &n);
	for (g = 0, i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		g = gcd(g, a[i]);
	}
	for (i = 1; i <= n; ++i)
		for (j = a[i] / g; j > 1; )
			for (++s[x = u[j]]; u[j] == x; )
				j /= u[j];
	for (i = 1; i <= MX; ++i)
		ans = max(ans, s[i]);
	printf("%d", ans ? n - ans: -1);
	return 0;
}