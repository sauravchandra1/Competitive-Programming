#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		if(n%2==0){
			int first=2,sec=1;
			for(int i=1;i<=n/2;i++){
				printf("%d %d ",first,sec);
				first+=2;
				sec+=2;
			}
		}
		else{
			int first=2,sec=1;
			for(int i=1;i<=(n-3)/2;i++){
				printf("%d %d ",first,sec);
				first+=2;
				sec+=2;
			}
			printf("%d %d %d",n-1,n,n-2);
		}
		printf("\n");
	}
	return 0;
} 
