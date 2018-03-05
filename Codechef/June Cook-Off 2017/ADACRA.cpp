#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--){
		char str[51];
		cin>>str;
		int len=strlen(str);
		if(len==1)
			cout<<"0"<<endl;
		else{
			char ch=str[0];
			int first=1,second=0,x=0;
			for(int i=1;i<len;i++){
				if(x==0){
					if(str[i]!=ch){
						second++;
						ch=str[i];
						x=1;
						continue;
					}
				}
				if(x==1){
					if(str[i]!=ch){
						first++;
						ch=str[i];
						x=0;
					}
				}
			}
			if(first<=second)
				cout<<first<<endl;
			else
				cout<<second<<endl;
		}
	}
	return 0;
}
		
