#include <bits/stdc++.h>
using namespace std;
#define N 1003
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		string str[N];
		for (int i = 0; i < n; i++) 
			cin >> str[i];
		int flag = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < (int)str[i].size(); j++) {
				if (str[i][j] == '.') {
					flag = 1;
					if (i - 1 >= 0 && j + 1 < m) 
						if (str[i - 1][j + 1] == '.' && str[i - 1][j] == '.' && str[i][j + 1] == '.')
							flag = 0;
					if (i - 1 >= 0 && j - 1 >= 0)
						if (str[i - 1][j - 1] == '.' && str[i - 1][j] == '.' && str[i][j - 1] == '.')
							flag = 0;
					if (i + 1 < n && j - 1 >= 0)
						if (str[i + 1][j] == '.' && str[i + 1][j - 1] == '.' && str[i][j - 1] == '.')
						flag = 0;
					if (i + 1 < n && j + 1 < m) 
						if (str[i + 1][j + 1] == '.' && str[i + 1][j] == '.' && str[i][j + 1] == '.')
						flag = 0;
					if (flag == 1)
						ans = 1;
				}
			}
		}
		if (ans)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}