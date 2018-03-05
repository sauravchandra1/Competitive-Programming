#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 6;
ll arr[N];

int main() {
	int t, cnt = 0;
	scanf("%d", &t);
	while(t--) {
		cnt++;
		int siz, flag = 0;
		ll ans = 0, sum = 0;
		scanf("%d", &siz);
		for(int i = 0;i < siz;i++)
			scanf("%lld", &arr[i]);
		for(int i = 0;i < siz;i++) {
			sum += arr[i];
			if(sum <= 0) {
				ans += 1 - sum;
				sum = 1;
				flag = 1;
			}
		}
		if(!flag)
			ans++;
		printf("Scenario #%d: %lld\n",cnt, ans);
	}
	return 0;
}
