#include <bits/stdc++.h>
using namespace std;

int main(){

	while(1){

		int n,ans=0;
		scanf("%d",&n);

		if(n==0)
			break;

		for(int i=1;i<=n;i++)
			ans+=(n-i+1)*(n-i+1);
		
		printf("%d\n",ans);
	}
	return 0;
}