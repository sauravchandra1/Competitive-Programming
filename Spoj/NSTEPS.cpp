#include <bits/stdc++.h>
using namespace std;

int main(){

	int test;
	scanf("%d",&test);

	while(test--){

		int x,y,ans=0;
		scanf("%d %d",&x,&y);

		if(x==y){

			ans=(x/2)*2+x;
			printf("%d\n",ans);
		}
		else if(x-y==2){

			ans=(x/2-1)*2+x;
			printf("%d\n",ans);
		}
		else 
			printf("No Number\n");

	}
	return 0;
}