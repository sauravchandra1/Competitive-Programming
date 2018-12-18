#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		if ((int)s.size() % 2 != 0) {
			cout << "no" << endl;
			continue;
		}
		if ((s.size() == 2 && s[0] == s[1])) {
			cout << "no" << endl;
			continue;
		}
		int flag = 0;
		for (int i = 1; i < (int)s.size(); i++) {
			if (s[i] == s[i - 1]) {
				flag = 1;
				break;
			}
		}
		if (s[0] == s[(int)s.size() - 1])
			flag = 1;
		if (flag == 0) {
			cout << "yes" << endl;
			continue;
		}
		int r = 0, g = 0;
		for (int i = 1; i < (int)s.size(); i++) {
			if (s[i] == s[i - 1]) {
				if (s[i] == 'R')
					r++;
				else 
					g++;
			}
		}
		if (s[0] == s[s.size() - 1]) {
			if (s[0] == 'R')
				r++;
			else
				g++;
		}
		if ((r == 1 && g == 0) || (r == 0 && g == 1) || (r == 1 && g == 1))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}