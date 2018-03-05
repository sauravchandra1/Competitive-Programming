#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	set<ll> rep;
	int temp1=0,temp2=0,temp3=0;
	ll num=0;
	int count=0;
	scanf("%lld",&num);
	rep.insert(num);
	while(1){
		if(num==1){
			printf("%d\n",count);
			break;
		}
		temp1=num;
		num=0;
		while(temp1!=0){
			temp2=temp1%10;
			temp1/=10;
			num+=temp2*temp2;
		}
		count++;
		temp3=rep.size();
		rep.insert(num);
		if(temp3==rep.size()){
			printf("-1\n");
			break;
		}
	}
	return 0;
}
		
			
