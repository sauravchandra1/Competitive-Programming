#include <bits/stdc++.h>
using namespace std;

int dp[105][105];

int lcs(char str1[],char str2[],int len1,int len2){
	if(len1==-1||len2==-1)
		return 0;
	else if(dp[len1][len2]!=-1)
		return dp[len1][len2];
	else if(str1[len1]==str2[len2]){
		dp[len1][len2]=1+lcs(str1,str2,len1-1,len2-1);
		return dp[len1][len2];
	}
	else{
		dp[len1][len2]=max(lcs(str1,str2,len1,len2-1),lcs(str1,str2,len1-1,len2));
		return dp[len1][len2];
	}
}
		
int main(){
	char str1[100],str2[100];
	scanf("%s %s",str1,str2);
	for(int i=0;i<105;i++)
		memset(dp[i],-1,105*sizeof(dp[0][0]));
	int len1=strlen(str1);
	int len2=strlen(str2);
	int ans=lcs(str1,str2,len1-1,len2-1);
	printf("%d\n",ans);	
	return 0;
}
