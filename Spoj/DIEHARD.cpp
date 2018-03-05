#include <bits/stdc++.h>
using namespace std;

int dp[1050][2000][4];

int max(int a,int b){
	return (a>b? a:b);
}

int mx_health(int num1,int num2,int mode){
	if(num1<=0||num2<=0)
		return -1;
	else if(dp[num1][num2][mode]!=-1)
		return dp[num1][num2][mode];
	else{
		if(mode==1)
			dp[num1][num2][mode]=max(mx_health(num1-5,num2-10,2)+1,mx_health(num1-20,num2+5,3)+1);
		else if(mode==2)
			dp[num1][num2][mode]=max(mx_health(num1+3,num2+2,1)+1,mx_health(num1-20,num2+5,3)+1);
		else
			dp[num1][num2][mode]=max(mx_health(num1+3,num2+2,1)+1,mx_health(num1-5,num2-10,2)+1);
		return dp[num1][num2][mode];
	}
}
			
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		memset(dp,-1,sizeof dp);
		int num1,num2;
		scanf("%d %d",&num1,&num2);
		int ans=mx_health(num1+3,num2+2,1)+1;
		printf("%d\n",ans);
	}
	return 0;
}
		
