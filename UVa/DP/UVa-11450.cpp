#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const ll mod = 1e9 + 7;
const int siz = 21;
const int sz = 201;

#define eb emplace_back
#define mp make_pair
#define OPEN 0

int main() {
	if (OPEN) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	int test;
	scanf("%d", &test);
	while (test--) {
		int money, garment, x;
		scanf("%d %d", &money, &garment);
		vector < int > model;
		vector < int > price[garment + 1];
		for (int i = 0; i < garment; i++) {
			scanf("%d", &x);
			model.eb(x);
			for (int j = 0; j < model[i]; j++) {
				scanf("%d", &x);
				price[i].eb(x);
			}
		}
		vector < vector < bool > > dp(siz, vector < bool > (sz, false));
		for (int i = 0; i < model[0]; i++) {
			dp[0][price[0][i]] = true;
		}
		for (int i = 1; i < garment; i++) {
			for (int j = 0; j <= 200; j++) {
				if (dp[i - 1][j] == false) {
						continue;
				}
				for (int k = 0; k < model[i]; k++) {
					dp[i][j + price[i][k]] = true;
				}
			}
		}
		while (dp[garment - 1][money] == false && money > 0) {
			money--;
		}
		if (money == 0) {
			printf("no solution\n");
		}
		else {
			printf("%d\n", money);
		}
	}
	return 0;
}
