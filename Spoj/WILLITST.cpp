#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n;
	scanf("%lld",&n);
	while(1){
		if(n==1){
			printf("TAK\n");
			break;
		}
		else if(!(n&1)){
			n=n>>1;
		}
		else{
			printf("NIE\n");
			break;
		}
	}
	return 0;
}