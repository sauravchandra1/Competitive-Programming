#include <bits/stdc++.h>
using namespace std;

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int num;
		scanf("%d",&num);
		if(num%2==0)
			printf("%d\n",num/2);
		else
			printf("%d\n",num/2+1);
	}
	return 0;
}
