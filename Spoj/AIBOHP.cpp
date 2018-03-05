#include <bits/stdc++.h>
using namespace std;

int dp[5005][5005];
string str1,str2;

int lcs(int len1,int len2){
	if(len1==-1||len2==-1)
		return 0;
	else if(dp[len1][len2]!=-1)
		return dp[len1][len2];
	else if(str1[len1]==str2[len2]){
		dp[len1][len2]=1+lcs(len1-1,len2-1);
		return dp[len1][len2];
	}
	else{
		dp[len1][len2]=max(lcs(len1,len2-1),lcs(len1-1,len2));
		return dp[len1][len2];
	}
}
		
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		cin>>str1;
		str2=str1;
		reverse(str2.begin(),str2.end());
		memset(dp,-1,sizeof dp);
		int len1=str1.size();
		int len2=str2.size();
		int ans=lcs(len1-1,len2-1);
		printf("%d\n",len1-ans);
	}	
	return 0;
}

