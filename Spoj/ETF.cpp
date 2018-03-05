#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int ans=n;
		if(n==1){
			cout<<"1"<<endl;
			continue;
		}
		else{
			int temp=n;
			if(temp%2==0){
				ans=n/2;
				while(temp%2==0){
					temp/=2;
				}
			}
			for(int i=3;i<=sqrt(temp);i+=2){
				if(temp%i==0){
					ans=(ans/i)*(i-1);
					while(temp%i==0){
						temp/=i;
					}
				}
			}
			if(temp==n){
				ans=n-1;
			}
			else if(temp>2){
				ans=(ans/temp)*(temp-1);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}