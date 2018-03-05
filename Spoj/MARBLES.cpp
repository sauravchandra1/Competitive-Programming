#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ncr(ll n,ll k){
	ll ans=1;
	if(k>n-k)
		k=n-k;
	for(ll i=0;i<k;i++){
		ans=ans*(n-i);
		ans/=(i+1);
	}
	return ans;
}
		
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		ll n,k;
		scanf("%lld %lld",&n,&k);
		ll ans=ncr(n-1,k-1);
		printf("%lld\n",ans);
	}
	return 0;
}
