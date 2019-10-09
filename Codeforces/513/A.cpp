#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == '8')
			cnt++;
	}
	int big = n / 11;
	cout << min(cnt, big) << endl;
	return 0;
}