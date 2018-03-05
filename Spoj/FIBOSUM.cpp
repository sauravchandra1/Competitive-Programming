#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

typedef long long ll;

void mul(ll a[][2],ll b[][2]){
	ll ans[2][2];
	memset(ans,0,sizeof ans);
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				ans[i][j]=((ans[i][j])%mod+(a[i][k]*b[k][j])%mod)%mod;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			a[i][j]=ans[i][j];
}

ll pwr(int n){
	ll fib[2][2]={{1,1},{1,0}},temp[2][2]={{1,0},{0,1}};
	while(n){
		if(n%2!=0)
			mul(temp,fib);
		mul(fib,fib);
		n>>=1;
	}
	return temp[0][1];
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int l,r;
		scanf("%d %d",&l,&r);
		printf("%lld\n",(pwr(r+2)-pwr(l+1)+mod)%mod);
	}
	return 0;
}
