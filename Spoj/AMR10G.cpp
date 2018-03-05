#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--){
		int n,k;
		cin>>n>>k;
		long long int *arr=new long long int[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		long long int diff=0,ans=0;
		int x=0;
		sort(arr,arr+n);
		if(k==1){
			cout<<"0"<<endl;
			continue;
		}
		else{
			k--;
			for(int i=0;i<n;i++){
				if((i+k)<n){
					diff=arr[i+k]-arr[i];
					if(x==0){
						ans=diff;
						x=1;
					}
					else{
						if(diff<ans)
							ans=diff;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}