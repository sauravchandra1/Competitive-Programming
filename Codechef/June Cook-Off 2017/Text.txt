#include<iostream>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		cout<<n<<endl;
		int a[110],b[110];
		for(int i=1;i<=n;i++){
				if(i!=n){
					a[i-1]=i;
					b[i-1]=i+1;
				}
				else{
					a[i-1]=1;
					b[i-1]=n;
				}
		}
		int count=1;
		for(int i=1;i<=n;i++){
			count=1;
			cout<<n<<endl;
			for(int j=i;j<=n;j++){
				cout<<count<<" ";
				count++;
				cout<<a[j-1]<<" "<<b[j-1]<<endl;
		    }
		    for(int k=0;k<i-1;k++){
				cout<<count<<" ";
				count++;
				cout<<a[k]<<" "<<b[k]<<endl;
		    }
		}
	}
	return 0;
}
