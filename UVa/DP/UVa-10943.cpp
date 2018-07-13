#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const ll mod = 1e6;
const int siz = 105;

#define eb emplace_back
#define mp make_pair
#define OPEN 0

int dp[siz][siz];

int main() {
	if (OPEN) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	for (int K = 0; K < siz; K++) 
		dp[0][K] = 1;	
	for (int N = 1; N < siz; N++) 
		for (int K = 1; K < siz; K++) 
			for (int m = 0; m <= N; m++) 
				dp[N][K] = (dp[N][K] % mod + dp[N - m][K - 1] % mod) % mod;
	int N, K;
	while (1) {
		scanf("%d %d", &N, &K);
		if (N == 0 && K == 0) 
			break;
		printf("%d\n", dp[N][K]);
	}
	return 0;
}
