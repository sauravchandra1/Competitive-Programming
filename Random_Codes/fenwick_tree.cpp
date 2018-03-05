#include <bits/stdc++.h>
using namespace std;

const int siz=1e5+5;

int arr[siz];
int FT[siz];

void updateFT(int n,int index,int val){
	index++;
	while(index<=n){
		FT[index]+=val;
		index+=index&(-index);
	}	
}

void constrFT(int n){
	for(int i=0;i<n;i++)
		updateFT(n,i,arr[i]);
			
}

int getsum(int n){
	n++;
	int sum=0;
	while(n>0){
		sum+=FT[n];
		n-=n&(-n);
	}
	return sum;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	constrFT(n);
	for(int i=0;i<n;i++)
		printf("%d ",getsum(i));
	printf("\n");
	return 0;
}
	
	
	
