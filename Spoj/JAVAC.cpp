#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
	while(cin>>str){
		int flag=0;
		int java=0,cpp=0;
		char ans[504];
		if(!(str[0]>=97&&str[0]<=122)){
			printf("Error!\n");
			continue;
		}
		for(int i=1;i<str.size();i++){
			if(str[i]<=90&&str[i]>=65)
				java=1;
			else if(str[i]=='_')
				cpp=1;
			if(java==1){
				if(str[i]=='_'){
					flag=1;
					break;
				}
			}
			else if(cpp==1){
				if(str[i]<=90){
					flag=1;
					break;
				}
			}
		}
		for(int i=0;i<str.size()-1;i++){
			if((str[i]=='_')&&(str[i+1]=='_')){
				flag=1;
				break;
			}
		}
		if(str[str.size()-1]=='_')
			flag=1;
		if((flag==1)||(java==1&&cpp==1)){
			printf("Error!\n");
			continue;
		}
		int i=0,j=0;
		if(java==0&&cpp==0)
			cout<<str<<endl;
		else if(cpp==1){
			while(i<str.size()){
				if(str[i]>=97){
					ans[j]=str[i];
					i++;
					j++;
				}
				else if(str[i]=='_'){
					ans[j]=char(str[i+1]-32);
					i+=2;
					j++;
				}
			}
			ans[j]='\0';
			printf("%s\n",ans);
		}
		else if(java==1){
			while(i<str.size()){
				if(str[i]>=97){
					ans[j]=str[i];
					i++;
					j++;
				}
				else if(str[i]<=90){
					ans[j]='_';
					j++;
					ans[j]=char(str[i]+32);
					i++;
					j++;
				}
			}
			ans[j]='\0';
			printf("%s\n",ans);
		}
	}
	return 0;
}
		
