#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const int siz=1e5+5;

int main(){
	int n,x,temp=0;
	scanf("%d %d",&n,&x);
	int arr[10000];
	memset(arr,0,10000*sizeof(arr[0]));
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		arr[temp]++;
	}
	int ans=0;
	for(int i=0;i<x;i++){
		if(arr[i]==0)
			ans++;
	}
	if(arr[x]!=0)
		ans++;
	printf("%d\n",ans);
	return 0;
}
