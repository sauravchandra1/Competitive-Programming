#include <bits/stdc++.h>
using namespace std;

int bus[105][105];
int dp[105][105];
int n,m;

int min(int a,int b,int c){
	if(a<b)
		return (a<c? a:c);
	else
		return (b<c? b:c);
}

int mn_cost(int row,int col){
	if(row<0||row>n-1||col<0||col>m-1)
		return INT_MAX;
	if(dp[row][col]!=-1)
		return dp[row][col];
	if(row==n-1)
		return bus[row][col];
	else{
		dp[row][col]=min(mn_cost(row+1,col),mn_cost(row+1,col-1),mn_cost(row+1,col+1))+bus[row][col];
		return dp[row][col];
	}
}

int main(){
	memset(dp,-1,sizeof dp);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&bus[i][j]);
	int ans=0,mn=INT_MAX;
	for(int i=0;i<m;i++){
		ans=mn_cost(0,i);
		if(ans<mn)
			mn=ans;
	}
	printf("%d\n",mn);
	return 0;
}
