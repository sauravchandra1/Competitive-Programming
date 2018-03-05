#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		ll n;
		scanf("%lld",&n);
		if(n&1){
			for(ll i=n-n/2;i<=n+n/2;i++)
				printf("%lld ",i);
		}
		else{
			for(ll i=n-n/2+1;i<=n+n/2;i++)
				printf("%lld ",i);
		}
		printf("\n");
	}
	return 0;
}