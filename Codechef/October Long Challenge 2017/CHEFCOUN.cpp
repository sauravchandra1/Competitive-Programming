#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		ll num;
		scanf("%lld",&num);
		ll un_int=4294967296;
		ll div=(un_int-3)/(num-2);
		printf("2 1 ");
		for(int i=0;i<num-3;i++)
			printf("%lld ",div);
		printf("%lld\n",un_int-div*(num-2));
	}
	return 0;
}
	
