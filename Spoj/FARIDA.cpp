#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int siz=1e4+4;
int arr[siz];

int main(){
	int test;
	scanf("%d",&test);
	int count=0;
	while(test--){
		count++;
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		ll curr_val=0,mx=0,priv_sum=0,temp=0;
		for(int i=0;i<n;i++){
			curr_val=arr[i];
			if(curr_val+priv_sum>mx){
				temp=mx;
				mx=curr_val+priv_sum;
				priv_sum=temp;
			}
			else
				priv_sum=mx;
		}
		printf("Case %d: %lld\n",count,mx);
	}
	return 0;
}
	 
		
