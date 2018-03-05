#include <bits/stdc++.h>
using namespace std;

int main(){

	while(1){

		int n;
		scanf("%d",&n);
		
		if(n==-1)
			break;

		int* arr=new int[n];
		long long int sum=0;

		for(int i=0;i<n;i++){

			scanf("%d",&arr[i]);
			sum+=arr[i];
		}

		if(sum%n==0){

			sum=sum/n;

			int ans=0;

			for(int i=0;i<n;i++)
				ans+=abs(sum-arr[i]);
			
			printf("%d\n",ans/2);
		}
		else
			printf("-1\n");

	}
	return 0;
}