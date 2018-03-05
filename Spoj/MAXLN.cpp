#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int test;
	int count=0;
	scanf("%d",&test);
	while(test--){
		count++;
		ll r=0;
		scanf("%lld",&r);
		ll ans=4*r*r;
		printf("Case %d: %lld.25\n",count,ans);
	}
	return 0;
}
