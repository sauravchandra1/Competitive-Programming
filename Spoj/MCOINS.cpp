#include <bits/stdc++.h>
using namespace std;

#define N 1000006

bool dp[N];

int main(){
	memset(dp,false,sizeof dp);
	int K,L,num;
	scanf("%d %d %d",&K,&L,&num);
	for(int i=1;i<N;i++){
		if(i-1>=0&&dp[i-1]==false)
			dp[i]=true;
		else if(i-L>=0&&dp[i-L]==false)
			dp[i]=true;
		else if(i-K>=0&&dp[i-K]==false)
			dp[i]=true;
	}
	int temp;
	for(int i=0;i<num;i++){
		scanf("%d",&temp);
		if(dp[temp])
			printf("A");
		else
			printf("B");
	}
	printf("\n");
	return 0;
}
