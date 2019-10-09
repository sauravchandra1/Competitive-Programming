#include <bits/stdc++.h>
using namespace std;

int main() {
	map < int, int > mp;
	mp[2010] = 1;
	mp[2015] = 1;
	mp[2016] = 1;
	mp[2017] = 1;
	mp[2019] = 1;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (mp.count(n) > 0)
			cout << "HOSTED" << endl;
		else
			cout << "NOT HOSTED" << endl;
	}
	return 0;
}