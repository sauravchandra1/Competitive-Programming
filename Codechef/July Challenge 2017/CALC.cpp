#include<iostream>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--){
		long long int n,b;
		cin>>n>>b;
		long long int mod=n%b;
		if(mod==0){
			mod=b;
			n=n-mod;
		}
		else{
			n=n-mod;
		}
		long long int div=n/b;
		div=div/2;
		n=n-div*b;
		mod=mod+div*b;
		cout<<(mod*n)/b<<endl;
	}
	return 0;
} 
