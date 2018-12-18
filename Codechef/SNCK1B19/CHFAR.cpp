#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector < int > vec(n);
		for (int i = 0; i < n; i++) 
			cin >> vec[i];
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (vec[i] != 1)
				cnt++;
		if (cnt <= k)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}