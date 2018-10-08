#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	long long n, m, k, n1, m1, k1;
	cin >> n >> m >> k;
	long long ansh = 2 * n * m;
	if (ansh % k) {
		cout << "NO" << endl;
		return 0;
	}
	if (k & 1) {
		n1 = n, m1 = m, k1 = k;
		long long kd = __gcd(k, n);
		n /= kd;
		k /= kd;
		m *= 2;
		m /= k;
		if (n > n1 || m > m1) {
			n = n1, m = m1, k = k1;
			long long kd = __gcd(k, m);
			m /= kd;
			k /= kd;
			n *= 2;
			n /= k;
		}
		if (n > n1 || m > m1) {
			if (n > n1) {
				n /= 2LL;
				m *= 2LL;
			}
			else {
				m /= 2LL;
				n *= 2LL;
			}
		}
	}
	else {
		k /= 2;
		long long kd = __gcd(k, n);
		n /= kd;
		k /= kd;
		m /= k;
	}
	cout << "YES" << endl;
	cout << "0 0" << endl;
	cout << n << " 0" << endl;
	cout << "0 " << m << endl;
	return 0;
}