#include <bits/stdc++.h>
using namespace std;

const int siz=2e5+5;

int arr[siz];

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		memset(arr,0,sizeof(arr));
		int num,k;
		scanf("%d %d",&num,&k);
		int x;
		for(int i=0;i<num;i++){
			scanf("%d",&x);	
			arr[x]=1;
		}
		for(int i=0;i<200001;i++){
			if(arr[i]==0&&k>0)
				k--;
			else if(arr[i]==0&&k==0){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
		
