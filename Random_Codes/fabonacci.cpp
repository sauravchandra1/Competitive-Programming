#include <bits/stdc++.h>
using namespace std;

int dp[100];

int fabonacci(int n){
	if(n==0)
		return dp[0];
	else if(n==1)
		return dp[1];
	else if(dp[n]!=-1)
		return dp[n];
	else{
		dp[n]=fabonacci(n-1)+fabonacci(n-2);
		return dp[n];
	}
}
	
int main(){
	int n;
	scanf("%d",&n);
	memset(dp,-1,sizeof dp);
	dp[0]=0,dp[1]=1;
	int ans=fabonacci(n);
	printf("%d\n",ans);
	return 0;
}
