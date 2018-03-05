#include <bits/stdc++.h>
using namespace std;

const int siz=2e5+5;

void merge(int arr[],int start,int mid,int end){
	int n1=mid-start+1;
	int n2=end-mid;
	int* Left=new int[n1];
	int* Right=new int[n2];
	int i=0;
	int j=0;
	int k=start;
	for(int i=0;i<n1;i++)
		Left[i]=arr[start+i];
	for(int i=0;i<n2;i++)
		Right[i]=arr[mid+1+i];
	while(i<n1&&j<n2){
		if(Left[i]<=Right[j]){
			arr[k]=Left[i];
			i++;
		}
		else{
			arr[k]=Right[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		arr[k]=Left[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k]=Right[j];	
		j++;
		k++;
	}
	return ;
}


void mergesort(int arr[],int start,int end){
	if(start>=end)
		return ;
	int mid=(start+end)/2;
	mergesort(arr,start,mid);
	mergesort(arr,mid+1,end);
	merge(arr,start,mid,end);
	return ;
}
		
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		ans=0;
		int arr[siz];
		int num;
		scanf("%d",&num);
		for(int i=0;i<num;i++)
			scanf("%d",&arr[i]);
		
		mergesort(arr,0,num-1);
		printf("%d\n",ans);
	}
	return 0;
} 
