#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		char ch;
		int ind = 0;
		int validd = 0;
		int valida = 0, validb = 0;
		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] == '.') {
				validd = 1;
			}
			if (s[i] == 'A') {
				valida = 1;
			}
			if (s[i] == 'B') {
				validb = 1;
			}
		}
		if (validd == (int)s.size()) {
			cout << "B" << endl;
			continue;
		}
		if (validd == 0 || valida == 0) {
			cout << "B" << endl;
			continue;
		}
		if (validb == 0) {
			int ans = 0;
			for (int i = 0; i < (int)s.size() - 1; i++) {
				if (s[i] == 'A' && s[i + 1] == '.') {
					ans = 1;
					break;
				}
			}
			if (ans) {
				cout << "A" << endl;
			}
			else 
				cout << "B" << endl;
			continue;
		}
		int flag = 0;
		vector<int> dir((int)s.size(), 0);
		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] != '.') {
				if (flag) {
					dir[i] = flag;
					flag = 1 - flag;
				}
				else {
					dir[i] = flag;
					flag = 1 - flag;
				}
			}
		}
		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] == 'A') {
				ch = 'A';
				ind = i;
				break;
			}
			else if (s[i] == 'B') {
				ch = 'B';
				ind = i;
				break;
			}
		}
		int sp = 0;
		int aint = 0, bint = 0, apow = 0, bpow = 0, isec = 0;
		for (int i = (int)s.size() - 1; i >= ind; i--) {
			if (s[i] == '.') {
				sp++;
				continue;
			}
			else if (s[i] == ch) {
				if (sp > 0) {
					if (isec == 0)
						apow++;
					else
						aint++;
				}
				sp = 0;
				isec = 0;
			}
			else {
				sp = 0;
				isec = 1;
			}
		}
		isec = 0;
		sp = 0;
		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] == '.') {
				sp++;
				continue;
			}
			else if (s[i] != ch) {
				if (sp > 0) {
					if (isec == 0)
						bpow++;
					else
						bint++;
				}
				sp = 0;
				isec = 0;
			}
			else {
				sp = 0;
				isec = 1;
			}
		}
		cout << aint << " " << apow << " " << bint << " " << bpow << endl;
		if (ch == 'A') {
			if (aint % 2 == 1) {
				if (bpow - 1 >= apow) {
					cout << "B" << endl;
				}
				else {
					cout << "A" << endl;
				}
			}
			else {
				if (bpow >= apow) {
					cout << "B" << endl;
				}
				else {
					cout << "A" << endl;
				}
			}
		}
		else {
			if (bint % 2 == 1) {
				if (apow - 1 >= bpow) {
					cout << "B" << endl;
				}
				else {
					cout << "A" << endl;
				}
			}
			else {
				if (apow >= bpow) {
					cout << "B" << endl;
				}
				else {
					cout << "A" << endl;
				}
			}
		}
	}
	return 0;
}