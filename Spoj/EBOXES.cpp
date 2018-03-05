#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		ll n, k, t, f;
		scanf("%lld %lld %lld %lld", &n, &k, &t, &f);
		printf("%lld\n", ((f - n) / (k - 1)) * k + n);
	}
	return 0; 
}
