#include <bits/stdc++.h>
using namespace std;

string s1,s2;
int dp[2005][2005];

int min(int x,int y,int z){
	return min(min(x,y),z);
}

int editdis(int len1,int len2){
	if(len1<0)
		return len2+1;
	else if(len2<0)
		return len1+1;
	else if(dp[len1][len2]!=-1)
		return dp[len1][len2];
	else if(s1[len1]==s2[len2]){
		dp[len1][len2]=editdis(len1-1,len2-1);
		return dp[len1][len2];
	}
	else{
		dp[len1][len2]=1+min(editdis(len1,len2-1),editdis(len1-1,len2),editdis(len1-1,len2-1));
		return dp[len1][len2];
	}	
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		memset(dp,-1,sizeof dp);
		cin>>s1>>s2;
		int len1=s1.size(),len2=s2.size();
		int ans=editdis(len1-1,len2-1);
		printf("%d\n",ans);
	}	
	return 0;
}
