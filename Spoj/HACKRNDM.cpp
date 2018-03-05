#include <bits/stdc++.h>
using namespace std;

#define N 100005

int arr[N];

int main(){
	int num,k;
	scanf("%d %d",&num,&k);
	for(int i=0;i<num;i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+num);
	int cnt=0;
	for(int i=0;i<num;i++){
		int low=lower_bound(arr,arr+num,arr[i]+k)-arr;
		int up=upper_bound(arr,arr+num,arr[i]+k)-arr;
		if(up-low>0)
			cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
