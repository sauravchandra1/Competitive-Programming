#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 10004

ll arr[N];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		ll ans = 0, diff = 0, temp = 0;
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
			scanf("%lld", &arr[i]);
		for(int i = 1;i < n;i++)
			ans += abs(arr[i] - arr[0]);
		temp = ans;
		for(int i = 0;i < n - 1;i++) {
			diff = abs(arr[i] - arr[i + 1]);
			diff *= n - i - 1;
			temp -= diff;
			ans = ans + temp;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
