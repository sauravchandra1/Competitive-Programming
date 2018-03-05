#include <bits/stdc++.h>
using namespace std;

const int siz=1e6+5;
int arr[siz];
int tree[4*siz];

int max(int a,int b){
	return (a>b? a:b);
}

void build(int low,int high,int pos){
	if(low==high){
		tree[pos]=arr[low];
		return ;
	}
	int mid=(low+high)/2;
	int left=2*pos+1;
	int right=2*pos+2;
	build(low,mid,left);
	build(mid+1,high,right);
	tree[pos]=max(tree[left],tree[right]);
	return ;
}

int query(int low,int high,int start,int end,int pos){
	if(high<start||low>end)
		return INT_MIN;
	else if(low>=start&&high<=end)
		return tree[pos];
	else{
		int mid=(low+high)/2;
		int left=2*pos+1;
		int right=2*pos+2;
		int a=query(low,mid,start,end,left);
		int b=query(mid+1,high,start,end,right);
		return max(a,b);
	}
}

int main(){
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
		scanf("%d",&arr[i]);
	int k;
	scanf("%d",&k);
	build(0,num-1,0);
	int mx=0;	
	for(int i=0;i<num-k+1;i++){
		mx=query(0,num-1,i,i+k-1,0);
		printf("%d ",mx);
	}
	printf("\n");
	return 0;
}	
