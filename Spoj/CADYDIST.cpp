#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
ll ans;

int main() {
	while(true) {
		ans = 0;
		int n, temp;
		scanf("%d", &n);
		if(!n)
			break;
		vector< ll > clas, candy;
		for(int i = 0;i < n;i++) {
			scanf("%d", &temp);
			clas.pb(temp);
		}
		for(int i = 0;i < n;i++) {
			scanf("%d", &temp);
			candy.pb(temp);
		}
		sort(clas.begin(), clas.end(), greater< ll >());
		sort(candy.begin(), candy.end());
		for(int i = 0;i < n;i++)
			ans += candy[i] * clas[i];
		printf("%lld\n", ans);
	}
	return 0;
}
		
