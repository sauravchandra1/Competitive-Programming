#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		ll x=0,y=0,sum=0;
		scanf("%lld%lld%lld",&x,&y,&sum);	
		ll n=(sum*2)/(x+y);
		ll d=(y-x)/(n-5);
		ll a=x-2*d;
		printf("%lld\n",n);
		for(ll i=0;i<n;i++)
			printf("%lld ",a+i*d);
		printf("\n");
	}
	return 0;
}
