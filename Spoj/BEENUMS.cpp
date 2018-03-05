#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	while(true){
		ll num;	
		scanf("%lld",&num);
		if(num==-1)
			break;
		num--;
		if(num%3!=0){
			printf("N\n");
			continue;	
		}
		else{
			num/=3;
			num*=4;
			num++;
			int root=sqrt(num);
			if((root*root)!=num){
				printf("N\n");
				continue;
			}
			else{
				if(root%2==0)
					printf("N\n");
				 else
					printf("Y\n");
			}
		}
	}
	return 0;
}
