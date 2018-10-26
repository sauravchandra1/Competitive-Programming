#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const ll mod = 1e9 + 7;
const int siz = 1e5 + 5;

#define eb emplace_back
#define mp make_pair
#define OPEN false

int main() {
	if (OPEN) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	int test;
	scanf("%d", &test);
	while (test--) {
		int n;
		scanf("%d", &n);
		if (n == 0) {
			printf("0\n");
			continue;
		}
		vector < pii > vec;
		int x;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			vec.eb(mp(x, 1));
		}
		int mx = 0, ans = 1;
		for (int i = 1; i < int(vec.size()); i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (vec[i].first > vec[j].first) {
					mx = vec[j].second + 1;
					vec[i].second = max(vec[i].second, mx);

				}
			}
			ans = max(ans, vec[i].second);
		}
		printf("%d\n", ans);
	}
	return 0;
}
