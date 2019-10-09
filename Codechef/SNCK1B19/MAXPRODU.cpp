#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main() {
	int t;
	cin >> t;
	while (t--) {
		long long n, k;
		cin >> n >> k;
		if (n < (k * (k + 1)) / 2) {
			cout << "-1" << endl;
			continue;
		}
		long long ax, sum;
		ax = k;
		k--;
		sum = (k * (k + 1)) / 2;
		long long starting = (n - sum) / ax;
		k++;
		long long rem = (n - sum) % ax;
		long long res = 1, ending = starting + k - 1, val;
		for (int i = k; i >= 1; i--) {
			val = ending;
			ending--;
			if (rem > 0) {
				val++;
				rem--;
			}
			res = (res % MOD * (val % MOD * (val - 1) % MOD) % MOD) % MOD;
		}
		cout << res << endl;
	}
	return 0;
}