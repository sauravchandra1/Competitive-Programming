#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const ll mod = 1e9 + 7;
const int siz = 1e5 + 5;
const int MAX_LIM = 7500;

#define eb emplace_back
#define mp make_pair
#define OPEN 0

int dp[6][MAX_LIM];

int main() {
	if (OPEN) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	vector < int > vec = {0, 1, 5, 10, 25, 50};
	int n;
	for (int i = 1; i < int(vec.size()); i++) {
		for (int mon = 1; mon < MAX_LIM; mon++) {
			if (mon < vec[i]) 
				dp[i][mon] = dp[i - 1][mon];
			else {
				n = vec[i];
				dp[i][mon] = dp[i - 1][mon];
				while (mon - n >= 0) {
					if (mon - n == 0) 
						dp[i][mon]++;
					else {
						dp[i][mon] += dp[i - 1][mon - n]; 
					}
					n += vec[i];
				}
			}
		}
	}
	while (cin >> n) 
		printf("%d\n", dp[5][n]);
	return 0;
}
