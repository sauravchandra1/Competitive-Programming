#include <bits/stdc++.h>
using namespace std;

int arr1[1005];
int arr2[1005];

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		memset(arr1,0,sizeof arr1);
		memset(arr2,0,sizeof arr2);
		int num1,num2;
		scanf("%d",&num1);
		for(int i=0;i<num1;i++)
			scanf("%d",&arr1[i]);
		scanf("%d",&num2);
		for(int i=0;i<num2;i++)
			scanf("%d",&arr2[i]);
		sort(arr1,arr1+num1);
		sort(arr2,arr2+num2);
		int mn=INT_MAX;
		for(int i=0;i<num1;i++){
			for(int j=0;j<num2;j++){
				if(abs(arr1[i]-arr2[j])<mn)
					mn=abs(arr1[i]-arr2[j]);
			}
		}
		printf("%d\n",mn);
	}
	return 0;
}				
		
			
