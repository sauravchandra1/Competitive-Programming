#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll num;
	scanf("%lld",&num);
	if(num%10!=0){ 
		printf("1\n%lld\n",num%10);
	}
	else 
		printf("2\n");
	return 0;
}
