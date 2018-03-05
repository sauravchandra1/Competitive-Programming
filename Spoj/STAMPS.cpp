#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int test;
	scanf("%d",&test);
	int temp=0;
	while(test--){
		temp++;
		ll total,sum=0;
		int n;
		scanf("%lld %d",&total,&n);
		int* arr=new int[n];
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		sort(arr,arr+n,greater<int>());
		int count=0,flag=0;
		for(int i=0;i<n;i++){
			sum+=arr[i];
			count++;
			if(sum>=total){
				printf("Scenario #%d:\n%d\n\n",temp,count);
				flag=1;
				break;
			}
		}
		if(flag==0)
			printf("Scenario #%d:\nimpossible\n\n",temp);
	}
	return 0;
}