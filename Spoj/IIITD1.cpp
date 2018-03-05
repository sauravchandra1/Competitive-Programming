#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int digit(int n){
	int count=0;
	while(n!=0){
		count++;
		n/=10;
	}
	return count;
}	

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int num;
		scanf("%d",&num);
		if(num==0){
			printf("1\n");
			continue;
		}
		int dig=digit(num),msd;
		if(dig!=1)
			msd=num/(dig-1);
		else
			msd=num;
		if(num>0){
			if(msd!=9){
				printf("1");
				for(int i=0;i<dig-1;i++)
					printf("0");
				printf("\n");
			}
			else{
				printf("1");
				for(int i=0;i<dig-2;i++)
					printf("0");
				printf("\n");	
			}
		}
		else{
			msd=-msd;
			ll num1=-num;
			ll sum=pow(10,dig-1);
			sum+=num1;
			printf("%lld\n",sum+num1);			
		}
	}	
	return 0;
}

