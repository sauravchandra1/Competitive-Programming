#include <bits/stdc++.h>
using namespace std;

const int siz=1e7+5;
typedef long long ll;

int arr[siz];
ll FT[siz];
ll sum=0;

ll getsum(int index){
	ll temp=0;
	while(index>0){
		temp+=FT[index];
		index-=index&-index;
	}
	return temp;
}

void updateFT(int index){
	sum+=getsum(index-1);
	while(index<siz){
		FT[index]++;
		index+=index&-index;
	}
}

void constructFT(int n){
	for(int i=n;i>=1;i--)
		updateFT(arr[i]);
		
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		sum=0;
		memset(arr,0,sizeof arr);
		memset(FT,0,sizeof FT);
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&arr[i]);
		constructFT(n);
		printf("%lld\n",sum);
	}
	return 0;
}
		
		
