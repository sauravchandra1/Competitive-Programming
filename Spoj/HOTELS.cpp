#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll num,limit;
	scanf("%lld %lld",&num,&limit);
	int* arr=new int[num];
	for(int i=0;i<num;i++)
		scanf("%d",&arr[i]);
	int ptr=0;
	ll mx=0,sum=0;
	for(int i=0;i<num;i++){
		sum+=arr[i];
		while(sum>limit){
			sum-=arr[ptr];
			ptr++;
		}
		if(sum>mx)
			mx=sum;
	}
	printf("%lld\n",mx);
	return 0;
}
