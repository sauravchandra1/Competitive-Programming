#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;

int main(){
	int n;
	scanf("%d",&n);
	int* arr=new int[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	ll temp=1;
	int flag=0;
	for(int i=0;i<n;i++){
		if(arr[i]%2!=0&&flag==0){
			temp=temp*((arr[i]+1)/2)%mod;
			flag=1;
		}
		else
			temp=temp*(arr[i]+1)%mod;
	}
	ll ans=1;
	if(flag==1)
		for(int i=0;i<n;i++)
			ans=ans*(((temp*arr[i])%mod+1)%mod)%mod;
	else
		for(int i=0;i<n;i++)
			ans=ans*(((temp*(arr[i]/2))%mod+1)%mod)%mod;
	printf("%lld\n",ans);
	return 0;
}
