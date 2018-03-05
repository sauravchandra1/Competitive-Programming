#include <bits/stdc++.h>
using namespace std;

struct start{
	int i,j;
};

int row,col;
int path[55][55];
int dp[55][55];
start arr[2505];

int max(int a,int b,int c,int d,int e,int f,int g,int h){
	int mx=-1;
	if(a>mx)
		mx=a;
	if(b>mx)
		mx=b;
	if(c>mx)
		mx=c;
	if(d>mx)
		mx=d;
	if(e>mx)
		mx=e;
	if(f>mx)
		mx=f;
	if(g>mx)
		mx=g;
	if(h>mx)
		mx=h;
	return mx;
}

int find_path(int i,int j,int val){
	if(i<0||i>row-1||j<0||j>col-1)
		return 0;
	else if(path[i][j]!=val)
		return 0;
	else if(dp[i][j]!=-1)
		return dp[i][j];	
	else{
		dp[i][j]=max(find_path(i,j-1,val+1),find_path(i,j+1,val+1),find_path(i-1,j,val+1),find_path(i+1,j,val+1),
			find_path(i-1,j-1,val+1),find_path(i-1,j+1,val+1),find_path(i+1,j-1,val+1),find_path(i+1,j+1,val+1))+1;
		return dp[i][j];
	}
}

int main(){
	int cnt=0;
	while(1){
		cnt++;
		memset(dp,-1,sizeof dp);
		scanf("%d %d",&row,&col);
		if(row==0&&col==0)
			break;
		scanf("\n");
		char ch;
		int k=0;
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				scanf("%c",&ch);
				path[i][j]=int(ch);
				if(path[i][j]==65){
					arr[k].i=i;
					arr[k].j=j;
					k++;
				}
			}
			if(i<row-1)
				scanf("\n");
		}
		int ans=0,mx=0;
		for(int i=0;i<k;i++){
			ans=find_path(arr[i].i,arr[i].j,65);
			if(ans>mx)
				mx=ans;
		}
		printf("Case %d: %d\n",cnt,mx);			
	}	
	return 0;
}
		
