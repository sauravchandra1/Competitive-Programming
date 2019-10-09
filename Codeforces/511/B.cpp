#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	long long x, y, big = INT_MIN;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (x + y > big)
			big = x + y;
	}
	cout << big << endl;
	return 0;
}