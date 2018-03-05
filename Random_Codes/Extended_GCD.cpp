#include <bits/stdc++.h>
using namespace std;

int extended_gcd(int r1, int r2) {
	int q, r, t1 = 0, t2 = 1, t;
	while(r2 != 0) {
		q = r1 / r2;
		r = r1 % r2;
		t = t1 - (q * t2);
		r1 = r2;
		r2 = r;
		t1 = t2;
		t2 = t;
	}
	if(r1 != 1)
		return 0;
	else
		return t1;	
}

int main() {
	int a, b, ans = 0;
	scanf("%d %d", &a, &b);
	ans = extended_gcd(a, b);
	if(ans != 0) 
		printf("%d\n", ans);
	else
		printf("Inverse is not possibe.\n");
	return 0;
}
