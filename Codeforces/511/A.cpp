#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	long long n;
	cin >> n;
	if (n == 3)
		cout << "1 1 1" << endl;
	if (n >= 4) {
		if (n % 3 == 2)
			cout << n - 3 << " 2 1" << endl;
		else 
			cout << n - 2 << " 1 1 " << endl;		
	}
	return 0;
}