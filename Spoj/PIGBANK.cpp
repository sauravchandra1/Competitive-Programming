#include <bits/stdc++.h>
using namespace std;

struct data{
	int val;
	int weight;
};

bool compare(data a,data b){
	if(a.weight<b.weight)
		return true;
	else 
		return false;
}

data arr[505];
int dp[100005];
int q;

int find_mn(int num){
	if(num==0)
		return 0;
	else if(dp[num]!=-1)
		return dp[num];
	else{	
		int mn=INT_MAX;
		int temp=0,flag=0;
		for(int i=0;i<q;i++){
			if(arr[i].weight<=num){
				temp=find_mn(num-arr[i].weight);
				if(temp>=0){
					temp+=arr[i].val;
					flag=1;
					if(temp<mn)
						mn=temp;
				}
			}
			else
				break;
		}
		if(flag!=0){
			dp[num]=mn;
			return dp[num];
		}
		else{
			dp[num]=-2;
			return dp[num];
		}	
	}
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		memset(dp,-1,sizeof(dp));
		int e,f;
		scanf("%d %d",&e,&f);
		int num=f-e;
		scanf("%d",&q);
		for(int i=0;i<q;i++)
			scanf("%d %d",&arr[i].val,&arr[i].weight);
		sort(arr,arr+q,compare);
		int ans=find_mn(num);
		if(ans>=0)
			printf("The minimum amount of money in the piggy-bank is %d.\n",ans);
		else 
			printf("This is impossible.\n");
	}
	return 0;
}
				
