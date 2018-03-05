#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(ll num){
	ll temp=sqrt(num);
	if(temp*temp==num)
		return true;
	else 
		return false;
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		ll num;
		scanf("%lld",&num);
		ll sq;
		int flag=0;
		for(ll i=1;i<=sqrt(num);i++){
			sq=num-i*i;
			if(check(sq)){
				printf("Yes\n");
				flag=1;
				break;
			}
		}
		if(flag==0)
			printf("No\n");
	}
	return 0;
}
