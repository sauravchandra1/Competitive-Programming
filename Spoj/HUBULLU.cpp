#include <bits/stdc++.h>
using namespace std;

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int num1,num2;
		scanf("%d%d",&num1,&num2);
		if(num2==0)
			printf("Airborne wins.\n");
		else
			printf("Pagfloyd wins.\n");
	}
	return 0;
}
