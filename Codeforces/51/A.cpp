#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int dig = 0, small = 0, cap = 0;
		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] >= '0' && s[i] <= '9')
				dig++;
			else if (s[i] >= 'a' && s[i] <= 'z')
				small++;
			else
				cap++;
		}
		if (dig == 0) {
			if (cap >= 2) {
				for (int i = 0; i < (int)s.size(); i++) {
					if (s[i] >= 'A' && s[i] <= 'Z') {
						s[i] = '7';
						break;
					}
				}
			}
			else {
				for (int i = 0; i < (int)s.size(); i++) {
					if (s[i] >= 'a' && s[i] <= 'z') {
						s[i] = '7';
						break;
					}
				}
			}
		}
		if (small == 0) {
			if (cap >= 2) {
				for (int i = 0; i < (int)s.size(); i++) {
					if (s[i] >= 'A' && s[i] <= 'Z') {
						s[i] = 'a';
						break;
					}
				}
			}
			else {
				for (int i = 0; i < (int)s.size(); i++) {
					if (s[i] >= '0' && s[i] <= '9') {
						s[i] = 'a';
						break;
					}
				}
			}
		}
		if (cap == 0) {
			if (small >= 2) {
				for (int i = 0; i < (int)s.size(); i++) {
					if (s[i] >= 'a' && s[i] <= 'z') {
						s[i] = 'A';
						break;
					}
				}
			}
			else {
				for (int i = 0; i < (int)s.size(); i++) {
					if (s[i] >= '0' && s[i] <= '9') {
						s[i] = 'A';
						break;
					}
				}
			}
		}
		cout << s << endl;
	}
	return 0;
}