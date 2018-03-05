#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		ll ans=0;
		int temp=0;
		int* arr=new int[n];
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		for(int i=0;i<n;i++){
			temp=arr[i];
			while(!(temp&1)){
				ans++;
				temp=temp>>1;
			}
		}
		if(ans%2==0)
			printf("Alan\n");
		else
			printf("Charlie\n");
	}
	return 0;
}
