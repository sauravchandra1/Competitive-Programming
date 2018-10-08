#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	if (n < 10)
		cout << n << endl;
	else {
		int digit = 0;
		long long tmp = n;
		while (tmp) {
			tmp /= 10LL;
			digit++;
		}
		tmp = n;
		int dig, flag = 0;
		while (tmp) {
			dig = tmp % 10LL;
			tmp /= 10LL;
			if (dig != 9)
				flag = 1;
		}
		if (flag == 0) {
			cout << digit * 9 << endl;
			return 0;
		}
		int last = 0;
		tmp = n;
		while (tmp) {
			if (tmp <= 9) {
				last = tmp;
				break;
			}
			tmp /= 10LL;
		}
		if (last == 1) {
			long long one = 9;
			for (int i = 2; i <= digit - 1; i++)
				one = one * 10LL + 9LL;
			long long two = n - one;
			long long ans = 0;
			while (one) {
				ans += one % 10LL;
				one /= 10LL;
			}
			while (two) {
				ans += two % 10LL;
				two /= 10LL;
			}
			cout << ans << endl;
		}
		else {
			long long one = last - 1;
			for (int i = 2; i <= digit; i++)
				one = one * 10LL + 9LL;
			long long two = n - one;
			long long ans = 0;
			while (one) {
				ans += one % 10LL;
				one /= 10LL;
			}
			while (two) {
				ans += two % 10LL;
				two /= 10LL;
			}
			cout << ans << endl;
		}
	}
	return 0;
}