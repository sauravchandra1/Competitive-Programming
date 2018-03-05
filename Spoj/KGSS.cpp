#include <bits/stdc++.h>
using namespace std;

#define N 100005

int arr[N];

struct node{
	int mx;
	int s_mx;
}tree[4*N];

node find_mx(node A,node B){
	int a=A.mx;
	int b=A.s_mx;
	int c=B.mx;
	int d=B.s_mx;
	node temp;
	if(a>=b&&a>=c&&a>=d){
		if(b>=c&&b>=d){
			temp.mx=a;
			temp.s_mx=b;
			return temp;
		}
		else if(c>=b&&c>=d){
			temp.mx=a;
			temp.s_mx=c;
			return temp;
		}
		else if(d>=b&&d>=c){	
			temp.mx=a;
			temp.s_mx=d;
			return temp;
		}
	}
	else if(b>=a&&b>=c&&b>=d){
		if(a>=c&&a>=d){
			temp.mx=b;
			temp.s_mx=a;
			return temp;
		}
		else if(c>=a&&c>=d){
			temp.mx=b;
			temp.s_mx=c;
			return temp;
		}
		else if(d>=a&&d>=c){	
			temp.mx=b;
			temp.s_mx=d;
			return temp;
		}
	}
	else if(c>=a&&c>=b&&c>=d){
		if(a>=b&&a>=d){
			temp.mx=c;
			temp.s_mx=a;
			return temp;
		}
		else if(b>=a&&b>=d){
			temp.mx=c;
			temp.s_mx=b;
			return temp;
		}
		else if(d>=a&&d>=b){	
			temp.mx=c;
			temp.s_mx=d;
			return temp;
		}
	}
	else if(d>=b&&d>=c&&d>=a){
		if(b>=c&&b>=a){
			temp.mx=d;
			temp.s_mx=b;
			return temp;
		}
		else if(c>=b&&c>=a){
			temp.mx=d;
			temp.s_mx=c;
			return temp;
		}
		else if(a>=b&&a>=c){	
			temp.mx=d;
			temp.s_mx=a;
			return temp;
		}
	}
}

void build(int low,int high,int pos){
	if(low==high){
		tree[pos].mx=arr[low];
		tree[pos].s_mx=0;
		return ;
	}
	int mid=(low+high)/2;
	int left=2*pos+1;
	int right=2*pos+2;
	build(low,mid,left);
	build(mid+1,high,right);
	tree[pos]=find_mx(tree[left],tree[right]);
}

node query(int low,int high,int start,int end,int pos){
	if(low>end||high<start){
		node temp;
		temp.mx=0;
		temp.s_mx=0;
		return temp;
	}
	else if(low>=start&&high<=end)
		return tree[pos];
	int mid=(low+high)/2;
	int left=2*pos+1;
	int right=2*pos+2;
	node a=query(low,mid,start,end,left);
	node b=query(mid+1,high,start,end,right);
	return find_mx(a,b);
}

void update(int low,int high,int start,int end,int val,int pos){
	if(low>end||high<start)
		return ;
	if(low==high){
		tree[pos].mx=val;
		tree[pos].s_mx=0;
		return ;
	}
	int mid=(low+high)/2;
	int left=2*pos+1;
	int right=2*pos+2;
	update(low,mid,start,end,val,left);
	update(mid+1,high,start,end,val,right);
	tree[pos]=find_mx(tree[left],tree[right]);
}
	
int main(){
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
		scanf("%d",&arr[i]);
	build(0,num-1,0);
	int q;
	cin>>q;
	char ch;
	int x,y;
	int i,val;
	node ans;
	for(int j=0;j<q;j++){
		cin>>ch;
		if(ch=='Q'){
			cin>>x>>y;
			ans=query(0,num-1,x-1,y-1,0);
			printf("%d\n",ans.mx+ans.s_mx);
		}
		else{
			cin>>i>>val;
			update(0,num-1,i-1,i-1,val,0);
		}
	}
	return 0;
}
		
