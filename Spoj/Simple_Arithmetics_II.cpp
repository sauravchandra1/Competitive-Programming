#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--){
		long long int ans=0,i=0;
		char ch;
		int x=0;
		scanf("%lld\n",&ans);
		while(1){
			scanf("%c",&ch);
			if(ch=='=')
				break;
			scanf("%lld\n",&i);
			if(ch=='+')
				ans+=i;
			else if(ch=='-')
				ans-=i;
			else if(ch=='*')
				ans*=i;
			else if(ch=='/')
				ans/=i;	
		}
		cout<<ans<<endl;
	}
	return 0;
}