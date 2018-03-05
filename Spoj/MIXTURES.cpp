#include <bits/stdc++.h>
using namespace std;

struct data{
	int cost;
	int val;
};

int arr[100];
data dp[105][105];

data mn_smk(int low,int high){
	int mn_cost=INT_MAX;
	int mn_val=0;
	if(low==high){
		data temp;
		temp.cost=0;
		temp.val=arr[low];
		return temp;
	}
	if(dp[low][high].val!=-1)
		return dp[low][high];
	data l_data,r_data,temp;
	for(int k=low;k<high;k++){
		l_data=mn_smk(low,k);
		r_data=mn_smk(k+1,high);
		temp.cost=l_data.cost+r_data.cost+(l_data.val*r_data.val);
		temp.val=(l_data.val+r_data.val)%100;
		if(temp.cost<mn_cost){
			mn_cost=temp.cost;
			mn_val=temp.val;
		}			
	}
	dp[low][high].cost=mn_cost;
	dp[low][high].val=mn_val;
	return dp[low][high];
}

int main(){
	int num;
	while(cin>>num){
		for(int i=0;i<105;i++){
			for(int j=0;j<105;j++){
				dp[i][j].cost=0;
				dp[i][j].val=-1;
			}
		}
		for(int i=0;i<num;i++)
			scanf("%d",&arr[i]);
		data ans=mn_smk(0,num-1);
		printf("%d\n",ans.cost);
	}
	return 0;
}
