#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e6+7;

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		ll num;
		scanf("%lld",&num);
		ll ans=0;
		ans=(num*(num+1)+(num*(num-1))/2)%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
