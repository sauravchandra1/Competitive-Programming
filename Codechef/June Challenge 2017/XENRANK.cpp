#include<iostream>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--){
		long long int x,y;
		cin>>x>>y;
		long long int minus=y,rank;
		x=minus+x+1;
		rank=x*(x+1)/2;
		cout<<rank-minus<<endl;
	}
	return 0;
} 
