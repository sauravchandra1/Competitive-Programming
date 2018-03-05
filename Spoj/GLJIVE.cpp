#include <bits/stdc++.h>
using namespace std;

int main(){
	int arr[11];
	for(int i=0;i<10;i++)
		scanf("%d",&arr[i]);
	int sum=0;
	for(int i=0;i<10;i++){
		if(abs(sum-100)<abs(sum+arr[i]-100))
			break;
		else
			sum+=arr[i];
	}
	printf("%d\n",sum);
	return 0;
}
	
		
