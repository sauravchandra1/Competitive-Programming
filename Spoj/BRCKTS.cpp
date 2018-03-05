#include <bits/stdc++.h>
using namespace std;
 
#define N 30004
 
struct node{
	int open,close;
}tree[N*4];
 
string str;
 
node merge(node a,node b){
	node temp;	
	if(a.open-b.close>0)
		temp.open=a.open-b.close+b.open;
	else
		temp.open=b.open;
	if(b.close-a.open>0)
		temp.close=b.close-a.open+a.close;
	else
		temp.close=a.close;
	return temp;
}
 
void build(int low,int high,int pos){
	if(low==high){
		if(str[low]=='('){
			tree[pos].open=1;
			tree[pos].close=0;
		}
		else{
			tree[pos].open=0;
			tree[pos].close=1;
		}
		return ;
	}
	int mid=(low+high)/2;
	int left=2*pos+1;
	int right=2*pos+2;
	build(low,mid,left);
	build(mid+1,high,right);
	tree[pos]=merge(tree[left],tree[right]);
}
	
void update(int low,int high,int start,int end,int pos){
	if(low>end||high<start)
		return ;
	if(low==high){
		if(tree[pos].open==1){
			tree[pos].open=0;
			tree[pos].close=1;
		}
		else{
			tree[pos].open=1;
			tree[pos].close=0;
		}
		return ;
	}
	int mid=(low+high)/2;
	int left=2*pos+1;
	int right=2*pos+2;
	update(low,mid,start,end,left);
	update(mid+1,high,start,end,right);
	tree[pos]=merge(tree[left],tree[right]);
}
 
bool query(int low,int high,int pos){
	if(tree[pos].open==0&&tree[pos].close==0)
		return true;
	else
		return false;
}
 
int main(){
	int test=10;
	int cnt=0;
	while(test--){
		cnt++;
		int len;
		scanf("%d",&len);
		cin>>str;
		int q;
		scanf("%d",&q);
		int temp;
		build(0,len-1,0);
		bool ans;
		printf("Test %d:\n",cnt);
		while(q--){
			scanf("%d",&temp);
			if(temp==0){
				ans=query(0,len-1,0);
				if(ans)
					printf("YES\n");
				else
					printf("NO\n");
			}
			else
				update(0,len-1,temp-1,temp-1,0);
		}
	}
	return 0;
}
		
		 
