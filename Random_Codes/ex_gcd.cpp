#include <bits/stdc++.h>
using namespace std;

int gcd_extended(int a, int b, int* x, int* y) {
	if(a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd_extended(b%a, a, &x1, &y1);
	*x = y1 - (b / a) * x1;
	*y = x1;
	return d;
}

int main() {
	int a, b, x, y, ans = 0;
	scanf("%d %d", &a, &b);
	ans = gcd_extended(a, b, &x, &y);
	printf("%d - > %d %d\n", ans, x, y);
	return 0;
}
