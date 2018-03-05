#include<bits/stdc++.h>
using namespace std;
 
int main(){
 
	int test;
	cin>>test;
 
	while(test--){
 
		int n,d;
		cin>>n>>d;
 
		long long int sum=0,ans=0,div;
		long long int* arr=new long long int[n];
 
		for(int i=0;i<n;i++){
 
			cin>>arr[i];
			sum+=arr[i];
		}
 
		if(sum%n!=0){
 
			cout<<"-1"<<endl;
			continue;
		}
 
		div=sum/n;
 
		for(int i=0;i<n;i++){
 
			if(arr[i]!=div){
 
				if(arr[i]>div){
 
					if((i+d)<n){
 
						arr[i+d]+=arr[i]-div;
						ans+=arr[i]-div;
						arr[i]=div;
					}
				}
				else{
 
					if((i+d)<n){
 
						arr[i+d]-=div-arr[i];
						ans+=div-arr[i];
						arr[i]=div;
					}
				}
			}
 
			if(arr[i]!=div){
				cout<<"-1"<<endl;
				break;
			}
 
			if(i==n-1)
				cout<<ans<<endl;
		}
	}
 
	return 0;
}
 
