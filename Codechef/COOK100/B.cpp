#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int tr, dr, ts, ds;
		cin >> tr;
		map<int, int> mptr, mpdr;
		int x;
		for (int i = 0; i < tr; i++) {
			cin >> x;
			 mptr[x]++;
		}
		cin >> dr;
		for (int i = 0; i < dr; i++) {
			cin >> x;
			mpdr[x]++;
		}
		cin >> ts;
		int ans = 0;
		for (int i = 0; i < ts; i++) {
			cin >> x;
			if (mptr.count(x) > 0)
				;
			else
				ans = 1;
		}
		cin >> ds;
		for (int i = 0; i < ds; i++) {
			cin >> x;
			if (mpdr.count(x) > 0)
				;
			else
				ans = 1;
		}
		if (ans)
			cout << "no" << endl;
		else
			cout << "yes" << endl;
	}
	return 0;
}