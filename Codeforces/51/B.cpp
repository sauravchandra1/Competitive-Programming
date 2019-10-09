#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	long long l, r;
	cin >> l >> r;
	cout << "YES" << endl;
	long long cnt = l;
	for (long long i = 1; i <= (r - l + 1) / 2LL; i++) {
		cout << cnt << " " << cnt + 1 << endl;
		cnt += 2;
	}
	return 0;
}