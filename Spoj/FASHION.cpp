#include <bits/stdc++.h>
using namespace std;

int main(){

	int test;
	scanf("%d",&test);

	while(test--){

		int n;
		scanf("%d",&n);

		int* men=new int[n];
		int* women=new int[n];

		for(int i=0;i<n;i++)
			scanf("%d",&men[i]);

		for(int i=0;i<n;i++)
			scanf("%d",&women[i]);

		sort(men,men+n);
		sort(women,women+n);

		long long int ans=0;

		for(int i=0;i<n;i++)
			ans+=men[i]*women[i];
		
		printf("%lld\n",ans);
	}
	return 0;
}