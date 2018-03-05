#include <bits/stdc++.h>
using namespace std;

int dp[2005][2005];
int arr[2005];

int max(int a,int b){ return (a>b)? a:b; }

int mx_rev(int low,int high,int age){
	if(low==high){
		dp[low][high]=(age+1)*arr[low];
		return dp[low][high];
	}
	else if(dp[low][high]!=-1)
		return dp[low][high];
	else{
		dp[low][high]=max((mx_rev(low+1,high,age+1)+arr[low]*(age+1)),(mx_rev(low,high-1,age+1)+arr[high]*(age+1)));
		return dp[low][high];
	}
}

int main(){
	memset(dp,-1,sizeof dp);
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
		scanf("%d",&arr[i]);
	int ans=mx_rev(0,num-1,0);
	printf("%d\n",ans);
	return 0;
}
