#include <bits/stdc++.h>
using namespace std;

#define N 10000
#define MX 100

bool flag[N],lookup[N];
int ans[N];

void sieve(){
	flag[0]=flag[1]=1;
	for(int i=1000;i<N;i+=2)
		flag[i]=1;
	for(int i=3;i<MX;i++)
		if(!flag[i])
			for(int j=i*i,k=i<<1;j<N;j+=k)
				flag[j]=1;
}

int bfs(int start,int end){
	queue<int> que;
	memset(lookup,0,sizeof lookup);
	memset(ans,-1,sizeof ans);
	char temp[10],x;
	ans[start]=0;
	que.push(start);
	lookup[start]=1;
	int temp1,j,k;
	while(!que.empty()){
		temp1=que.front();
		que.pop();
		sprintf(temp,"%d",temp1);
		for(int i=0;i<4;i++){
			if(i==0||i==3)
				j=1;
			else
				j=0;
			x=temp[i];
			for(;j<=9;j++){
				temp[i]=j+'0';
				k=atoi(temp);
				if(!flag[k]&&k!=temp1&&!lookup[k]){
					que.push(k);
					lookup[k]=1;
					ans[k]=ans[temp1]+1;
					if(k==end)
						return ans[k];
				}
			}
			temp[i]=x;
		}
	}
	return ans[end];	
}

int main(){
	sieve();
	int test;
	scanf("%d",&test);
	while(test--){
		int num1,num2;
		scanf("%d %d",&num1,&num2);
		if(num1==num2){
			printf("0\n");
			continue;
		}
		int dist=bfs(num1,num2);
		if(dist==-1)
			printf("Impossible\n");
		else
			printf("%d\n",dist);
	}
	return 0;
}
	
