#include<iostream>
#include<climits>
#include<cstdint>
#include<cstring>

using namespace std;
#define INF LLONG_MIN
int check[1000];
int rodcutting(long long int prices[],int n){
	if(n==0)
		return 0;
	if(check[n]!=0)
		return check[n];
	long long int q=INF;
	for(int i=1;i<=n;i++){
		q=max(q,prices[i]+rodcutting(prices,n-i));
	}
	int y=q;
	check[n]=y;
	return y;
}
int main(){
	memset(check,0,1000*sizeof(check[0]));
	long long int prices[11]={0,1,5,8,9,10,17,17,20,24,30};
	int n;
	scanf("%d",&n);
	while(n--){
		int x;
		scanf("%d",&x);
		int y=rodcutting(prices,x);
		printf("%d\n",y);
	}
	return 0;
}