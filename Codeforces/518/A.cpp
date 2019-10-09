#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, m, k, l;
	cin >> n >> m >> k >> l;
	int flag = 0;
	if (n < m) 
		flag = 1;
	else if ((n - k) < l)
		flag = 1;
	if (flag) {
		cout << "-1" << endl;
		return 0;
	}
	long long nye = l + k;
	long long tot = nye / m;
	if (nye % m)
		tot++;
	if (tot * m <= n) {
		cout << tot << endl;
	}
	else 
		cout << "-1" << endl;
	return 0;
} 
