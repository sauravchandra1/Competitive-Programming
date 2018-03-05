#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll mod = 1e9 + 7;
 
#define pb push_back
#define mp make_pair
 
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		ll y, ans = 0, root = 0;
		scanf("%lld", &y);
		root = y - 700;
		if(root > 0)
			root = sqrt(root);
		else 
			root = 0;
		ans += (root * 700);
		root++;
		while((y - root * root) > 0) {
			ans += y - root * root;
			root++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
 
