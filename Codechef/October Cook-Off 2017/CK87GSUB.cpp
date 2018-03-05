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
		string S;
		cin >> S;
		ll ans = 0, cnt = 1;
		char ch, st;
		if(S.size() == 1) {
			printf("0\n");
			continue;
		}
		ch = S[0], st = S[0];
		for(unsigned int i = 1;i < S.size();i++) {
			if(S[i] == ch){
				cnt++;
			}
			else {
				if(cnt > 1)
					ans += cnt - 1 + ((cnt - 2) * (cnt - 1))/2;
				if(S[i] == st)
					ans++;
				st = ch;
				ch = S[i];
				cnt = 1;
			}
		}
		if(cnt > 1)
			ans += cnt - 1 + ((cnt - 2) * (cnt - 1))/2;
		printf("%lld\n", ans);			
	}
	return 0;
}
 
