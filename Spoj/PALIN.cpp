#include <bits/stdc++.h>
using namespace std;

string str;

void nextpalin(){
	int carry=0,temp=0;
	int len=str.size();
	len--;
	if(len%2==0){
		for(int i=0;i<=len/2;i++){
			if(str[i]!=str[len-i]){
				if(int(str[i])<int(str[len-i])){
					temp=int(str[len-i]-'0');
					carry=1;
					if(temp==9)
						str[len-i]='0';
					else
						str[len-i]=str[i];
					for(int j=len-i-1;j>=0;j--){
						if(carry==0)
							break;
						temp=int(str[j]-'0');		
						if(temp==9)
							str[j]='0';
						else{
							str[j]=int(str[j])+1;
							carry=0;
						}
					
					}
				}
				else
					str[len-i]=int(str[len-i])+1;
			}
		}
	}
	else{
		
	}
}
		
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		cin>>str;
		nextpalin();
		cout<<str<<endl;
	}
	return 0;
}	
