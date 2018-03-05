#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--){
		int x=0;
		char p[2000],q[2000];
		cin>>p>>q;
		int len=strlen(p);
		int check[10000]={0},ans[20000]={0};
		for(int i=0;i<len;i++){
			if(check[int(p[i])]==0){
				if(ans[int(q[i])]==1){
					cout<<"NO"<<endl;
					x=1;
					break;
				}
				check[int(p[i])]=int(q[i]);
				ans[int(q[i])]=1;
			}
			else if(check[int(p[i])]!=0){
				if(check[int(p[i])]!=int(q[i])){
					cout<<"NO"<<endl;
					x=1;
					break;
				}
			}
		}
		if(x==0)
			cout<<"YES"<<endl;
	}
	return 0;
}