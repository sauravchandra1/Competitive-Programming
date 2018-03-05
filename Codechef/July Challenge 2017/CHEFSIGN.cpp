#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--){
		char str[100004];
		cin>>str;
		int len=strlen(str);
		char ch='s';
		int ans=0,max=0;
		int x=0;
		for(int i=0;i<len;i++){
			if(x==0){
				if(str[i]!='='&&ch=='s'){
					ch=str[i];
					ans++;
					x=1;
					if(ans>max)
						max=ans;
					continue;
				}
			}
			if(x==1){
				if(str[i]=='=')
					continue;
				if(str[i]==ch)
					ans++;
				else{
					ans=1;
					ch=str[i];
				}
			}
			if(ans>max)
				max=ans;
		}
		cout<<max+1<<endl;
	}
	return 0;
} 
