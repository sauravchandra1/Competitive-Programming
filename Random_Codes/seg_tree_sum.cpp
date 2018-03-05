#include <bits/stdc++.h>
using namespace std;

const int siz=1e4+4;
int arr[siz];
int tree[4*siz];

void cons_tree(int low,int high,int pos){
	if(low==high){
		tree[pos]=arr[low];
		return ;
	}
	int mid=(low+high)/2;
	int left=2*pos+1;
	int right=2*pos+2;
	cons_tree(low,mid,left);	
	cons_tree(mid+1,high,right);
	tree[pos]=tree[left]+tree[right];
}

int query(int start,int end,int low,int high,int pos){
	if(low>=start&&high<=end)
		return tree[pos];
	else if(high<start||low>end)
		return 0;
	else{
		int mid=(low+high)/2;
		int left=2*pos+1;
		int right=2*pos+2;
		int a=query(start,end,low,mid,left);
		int b=query(start,end,mid+1,high,right);
		return a+b;
	}
}

int main(){
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
		scanf("%d",&arr[i]);
	cons_tree(0,7,0);
	int ans=query(0,4,0,7,0);
	printf("%d\n",ans);	
	return 0;
}
