#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		ll minimum=1e9;
		int x,index=0;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			if(x<minimum){
				minimum=x;
				index=i+1;
			}
		}
		printf("%d\n",index);
	}
	return 0;
} 
