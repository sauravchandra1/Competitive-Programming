#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const ll mod = 1e9 + 7;
const int siz = 1e5 + 9;

#define eb emplace_back
#define mp make_pair
#define OPEN 1

ll dp[20];

int main() {
	if (OPEN) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	ll N, K;
	scanf("%lld %lld", &N, &K);
	dp[0] = 0;
	dp[1] = K;
	dp[2] = K * (K - 1);
	if (N == 2) 
		printf("%lld\n", dp[2]);
	else {
		ll sum = dp[2];
		ll zero = (K - 1) * (K - 1), one = sum * (K - 1);
		for (int i = 3; i <= N; i++) {
			dp[i] = zero + one;
			sum = dp[i];
			zero = one;
			one = sum * (K - 1);
		}
		printf("%lld\n", dp[N]);
	}
	return 0;
}
