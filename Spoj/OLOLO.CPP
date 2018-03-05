#include<bits/stdc++.h>
using namespace std;

const int siz=5e6+5;
int arr[siz];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+n);
	int temp=0,flag=0;
	for(int i=0;i<n;i++){
		if(temp==0){
			temp=arr[i];
			continue;
		}
		else if(temp==arr[i])
			temp=0;
		else{
			printf("%d\n",temp);
			temp=0;
			break;
		}
	}
	if(temp!=0)
		printf("%d\n",temp);
	return 0;
}
