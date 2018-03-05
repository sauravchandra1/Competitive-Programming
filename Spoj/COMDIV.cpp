#include <bits/stdc++.h>
using namespace std;

int ans=0;

void fact(int num){
    for(int i=1;i<=sqrt(num);i++){
        if(num%i==0){
            if(num/i==i)
                ans+=1;
            else 
                ans+=2;
        }
    }
}

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
		int num1,num2,hcf;
		scanf("%d %d",&num1,&num2);
		if(num1<=num2)
			hcf=gcd(num2,num1);
		else
			hcf=gcd(num1,num2);
		ans=0;
		fact(hcf);
		printf("%d\n",ans);
	}
	return 0;
}
