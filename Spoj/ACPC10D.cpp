#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define N 1000006

int arr[N][3],num;
ll dp[N][3];

ll min(ll a,ll b){
	return (a<b? a:b);
}

ll min(ll a,ll b,ll c){
	if(a<b)
		return (a<c? a:c);
	else
		return (b<c? b:c);
}

ll min(ll a,ll b,ll c,ll d){
	if(a<b){
		if(a<c)
			return (a<d? a:d);
		else
			return (c<d? c:d);
	}
	else{
		if(b<c)
			return (b<d? b:d);
		else
			return (c<d? c:d);
	}
}

ll mn_cost(int i,int j){
	if(i==num-1&&j==1)
		return arr[i][j];
	if(i>num-1||i<0||j>2||j<0)
		return INT_MAX;
	else if(dp[i][j]!=-1)
		return dp[i][j];
	else{
		if(j==0)
			dp[i][j]=min(mn_cost(i,j+1),mn_cost(i+1,j),mn_cost(i+1,j+1))+arr[i][j];
		else if(j==1)
			dp[i][j]=min(mn_cost(i+1,j+1),mn_cost(i,j+1),mn_cost(i+1,j-1),mn_cost(i+1,j))+arr[i][j];
		else if(j==2)
			dp[i][j]=min(mn_cost(i+1,j),mn_cost(i+1,j-1))+arr[i][j];
		return dp[i][j];
	}				
}

int main(){
	int cnt=0;
	while(1){
		cnt++;
		memset(dp,-1,sizeof dp);
		scanf("%d",&num);
		if(num==0)
			break;
		for(int i=0;i<num;i++)
			for(int j=0;j<3;j++)
				scanf("%d",&arr[i][j]);
		ll ans=mn_cost(0,1);
		printf("%d. %lld\n",cnt,ans);
	}
	return 0;
}
	
