#include <bits/stdc++.h>
using namespace std;

int main(){

	int x;

	while(scanf("%d",&x)!=EOF){

		int i=1,ans=0;

		if(x==1){

			printf("1\n");
			continue;
		}

		while((x/i)>=i){

			ans+=(x/i)-i+1;
			i++;
		}

		printf("%d\n",ans);
	}
	return 0;
}