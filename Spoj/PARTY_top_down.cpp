#include <bits/stdc++.h>
using namespace std;

struct data{
	int dp_cost;
	int dp_fun;
};

data dp[105][505];
int cost[105];
int fun[105];
int par=0;

data mx_fun(int ind,int rem_cost){
	if(ind+1>par){
		data temp;
		temp.dp_cost=0;
		temp.dp_fun=0;
		return temp;
	}
	else if(rem_cost<cost[ind]){
		dp[ind][rem_cost]=mx_fun(ind+1,rem_cost);
		return dp[ind][rem_cost];
	}
	else if(dp[ind][rem_cost].dp_fun!=-1)
		return dp[ind][rem_cost];
	else{
		data a=mx_fun(ind+1,rem_cost);
		data b=mx_fun(ind+1,rem_cost-cost[ind]);
		if(a.dp_fun>b.dp_fun+fun[ind]){
			dp[ind][rem_cost].dp_fun=a.dp_fun;
			dp[ind][rem_cost].dp_cost+=a.dp_cost;
		}
	
		else{
			dp[ind][rem_cost].dp_fun=b.dp_fun+fun[ind];
			dp[ind][rem_cost].dp_cost+=b.dp_cost+cost[ind];
		}		
		return dp[ind][rem_cost];
	}
}

int main(){
	while(1){
		for(int i=0;i<105;i++){
			for(int j=0;j<505;j++){
				dp[i][j].dp_fun=-1;
				dp[i][j].dp_cost=0;	
			}
		}
		int bud;
		scanf("%d%d",&bud,&par);
		if(bud==0&&par==0)
			break;
		for(int i=0;i<par;i++)
			scanf("%d%d",&cost[i],&fun[i]);
		data ans=mx_fun(0,bud);
		printf("%d %d\n",ans.dp_cost,ans.dp_fun);
	}
	return 0;
}
