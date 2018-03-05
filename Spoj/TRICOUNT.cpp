#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		ull n;
		scanf("%llu",&n);
		ull ans=n*n+(n*n*(n+1))/2-(n*(n+1)*(2*n+1))/6;
		if(n>3){
			if(n%2==0)
				ans+=(n-2)/2*(n-2)/2;
			n-=3;
			n/=2;
			ans+=(n*(n+1)*(2*n+1))/3+n*(n+1)/2;
		}
		printf("%llu\n",ans);
	}
	return 0;
}		
