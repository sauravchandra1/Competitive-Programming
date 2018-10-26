#include <bits/stdc++.h>
using namespace std;
#define N 110
int arr[N + 10];
int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector < int  > vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		arr[vec[i]]++;
	}
	int cnt = 0;
	for (int i = 0; i < N; i++)
		if (arr[i] == 1)
			cnt++;
	if (cnt == 0) {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++)
			cout << 'A';
		return 0;
	}
	char ch = 'B';
	if (cnt & 1) {
		for (int i = 0; i < n; i++) {
			if (arr[vec[i]] >= 3) {
				int flag = 1;
				char print[N + 10];
				for (int i = 0; i < N; i++)
					print[i] = 'X';
				cout << "YES" << endl;
				for (int i = 0; i < n; i++) {
					if (arr[vec[i]] == 1) {
						if (ch == 'A')
							ch = 'B';
						else
							ch = 'A';
						cout << ch;
					}
					else {
						if (print[vec[i]] == 'X' && arr[vec[i]] >= 3 && flag) {
							if (ch == 'A')
								ch = 'B';
							else
								ch = 'A';
							cout << ch;
							if (ch == 'A')
								ch = 'B';
							else
								ch = 'A';
							print[vec[i]] = ch;
							if (ch == 'A')
								ch = 'B';
							else
								ch = 'A';
							flag = 0;
						}
						else {
							if (print[vec[i]] == 'X') 
								print[vec[i]] = ch;
							cout << print[vec[i]];
						}
					}
				}
				return 0;
			}
		}
		cout << "NO" << endl;
	}
	else {
		char print[N + 10];
		for (int i = 0; i < N; i++)
			print[i] = 'X';
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			if (arr[vec[i]] == 1) {
				if (ch == 'A')
					ch = 'B';
				else
					ch = 'A';
				cout << ch;
			}
			else {
				if (print[vec[i]] == 'X') 
					print[vec[i]] = ch;
				cout << print[vec[i]];
			}
		}
	}
	return 0;
}