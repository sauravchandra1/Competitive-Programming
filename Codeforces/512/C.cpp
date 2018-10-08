#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	string str1, str2;
	cin >> str1;
	for (int i = 0; i < (int)str1.size(); i++) 
		if (str1[i] != '0')
			str2 += str1[i];
	if ((int)str2.size() == 0) {
		cout << "YES" << endl;
		return 0;
	}
	int a = 0, b, flag = 0;
	for (int i = 0; i < (int)str2.size(); i++) {
		a += (int)(str2[i] - '0');
		b = 0;
		for (int j = i + 1; j < (int)str2.size(); j++) {
			b += (int)(str2[j] - '0');
			if (j == (int)str2.size() - 1 && b == a)
				flag = 1;
			if (b == a)
				b = 0;
		}
	}
	flag == 1 ? cout << "YES" << endl : cout << "NO" << endl;
	return 0;
}