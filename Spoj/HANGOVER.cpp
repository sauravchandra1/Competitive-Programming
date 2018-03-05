#include <bits/stdc++.h>
using namespace std;

int main(){
	while(1){
		float n;
		scanf("%f",&n);
		if(n==0.00)
			break;
		n*=100000000;
		int sum=0;
		int count=0,i=2;
		while(1){
			if(sum>=n)
				break;
			sum+=100000000/i;
			count++;
			i++;
		}
		printf("%d card(s)\n",count);
	}
	return 0;
}