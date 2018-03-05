#include<iostream>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--){
		long long int m;
		cin>>m;
		if(m%3==0){
			cout<<m/3<<" "<<(m/3)*2<<endl;
		}
		else if(m%3==1){
			cout<<m/3+1<<" "<<(m/3)*2<<endl;
		}
		else if(m%3==2){
			cout<<m/3+1<<" "<<(m/3)*2+1<<endl;
		}
	}
	return 0;
}