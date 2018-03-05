#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[100][100];

int bino(int n,int k){
	if(n==k||k==0)
		return 1;
	else if(dp[n][k]!=-1)
		return dp[n][k];
	else{
		dp[n][k]=bino(n-1,k-1)+bino(n-1,k);
		return dp[n][k];
	}
}

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	memset(dp,-1,sizeof dp);
	int ans=bino(n,k);
	printf("%d\n",ans);
	return 0;
}	
