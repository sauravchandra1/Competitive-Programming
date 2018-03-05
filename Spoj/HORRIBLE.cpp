#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int siz=1e5+5;
ll tree[4*siz];
ll lazy[4*siz];

void update(int start,int end,int low,int high,int pos,ll val){
	if(lazy[pos]!=0){
		ll temp=high-low+1;
		tree[pos]+=temp*lazy[pos];
		if(low!=high){
			lazy[2*pos+1]+=lazy[pos];
			lazy[2*pos+2]+=lazy[pos];
		}
		lazy[pos]=0;
	}
	if(high<start||low>end)
		return ;
	if(low>=start&&high<=end){
		ll temp=high-low+1;
		tree[pos]+=temp*val;
		if(low!=high){
			lazy[2*pos+1]+=val;
			lazy[2*pos+2]+=val;
		}
		return ;
	}
	int mid=(low+high)/2;
	int left=2*pos+1;
	int right=2*pos+2;
	update(start,end,low,mid,left,val);
	update(start,end,mid+1,high,right,val);
	tree[pos]=tree[left]+tree[right];
}

ll query(int start,int end,int low,int high,int pos){
	if(lazy[pos]!=0){
		ll temp=high-low+1;
		tree[pos]+=temp*lazy[pos];
		if(low!=high){
			lazy[2*pos+1]+=lazy[pos];
			lazy[2*pos+2]+=lazy[pos];
		}
		lazy[pos]=0;
	}
	if(high<start||low>end)
		return 0;
	if(high<=end&&low>=start)
		return tree[pos];
	int mid=(low+high)/2;
	int left=2*pos+1;
	int right=2*pos+2;
	return query(start,end,low,mid,left)+query(start,end,mid+1,high,right);
	
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		memset(lazy,0,sizeof(lazy));
		memset(tree,0,sizeof(tree));
		int num,q;
		scanf("%d %d",&num,&q);
		while(q--){
			int s,p,qur;
			ll v;
			scanf("%d",&s);
			if(s==0){
				scanf("%d %d %lld",&p,&qur,&v);
				update(p-1,qur-1,0,num-1,0,v);
			}
			else{
				scanf("%d %d",&p,&qur);
				ll ans=query(p-1,qur-1,0,num-1,0);	
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}
