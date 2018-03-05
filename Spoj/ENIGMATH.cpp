#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	if(b==0)
		return a;
	else 
		return gcd(b,a%b);
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int num1,num2;
		scanf("%d %d",&num1,&num2);
		int hcf;
		if(num1>num2)
			hcf=gcd(num1,num2);
		else
			hcf=gcd(num2,num1);
		printf("%d %d\n",num2/hcf,num1/hcf);
	}
	return 0;
}
