#include <bits/stdc++.h>
using namespace std;

int dp[105][105];
int arr[105][105];
int row,col;

int maximum(int x,int y,int z){
	if(x>y)
		return (x>z)? x:z;
	else
		return (y>z)? y:z;
}

int harry(int r,int c){
	if(r<0||c<0||r>=row||c>=col)
		return 0;			
	else if(dp[r][c]!=-1)
		return dp[r][c];
	else{
		dp[r][c]=arr[r][c]+maximum(harry(r-1,c-1),harry(r-1,c),harry(r-1,c+1));
		return dp[r][c];
	}
	return dp[r][c];
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%d%d",&row,&col);
		for(int i=0;i<105;i++)
			memset(dp[i],-1,105*sizeof(dp[0][0]));
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				scanf("%d",&arr[i][j]);
			}
		}
		int max=-1,ans=0;
		for(int i=0;i<col;i++){
			ans=harry(row-1,i);
			if(ans>max)	
				max=ans;
		}
		printf("%d\n",max);
	}
	return 0;
}
		
		
