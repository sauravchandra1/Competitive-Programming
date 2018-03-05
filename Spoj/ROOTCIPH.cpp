#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		long long  a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		printf("%lld\n", a * a - 2 * b);
	}
	return 0;
}
