#include <bits/stdc++.h>
using namespace std;

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int num,p;
		scanf("%d %d",&num,&p);
		int b_cake=p/2,b_hard=p/10;
		int cake=0,hard=0,x;
		for(int i=0;i<num;i++){
			scanf("%d",&x);
			if(x>=b_cake)
				cake++;
			else if(x<=b_hard)
				hard++;
		}
		if(cake==1&&hard==2)
			printf("yes\n");
		else 
			printf("no\n");
	}
	return 0;
}
