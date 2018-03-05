#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main (){
	int test;
	scanf("%d\n",&test);
	while(test--){
		char name[50];
		cin.getline(name,50);
		int index[3];
		int count=0;
		for(unsigned int i=0;i<strlen(name);i++){
			if(name[i] == ' '){
				count++;
				index[count-1]=i;
			}
		}
		if(count==0){
			if(name[0]>=97&&name[0]<=122)
				name[0]=int(name[0])-32;
			cout<<name[0];
			for(unsigned int i=1;i<strlen(name);i++){
				if(name[i]>=65&&name[i]<=90)
					name[i]=int(name[i])+32;
				cout<<name[i];
			}
			cout<<endl;
		}
		else if(count==1){
			if(name[0]>=97&&name[0]<=122)
				name[0]=int(name[0])-32;
			cout<<name[0]<<". ";
			if(name[index[0]+1]>=97&&name[index[0]+1]<=122)
				name[index[0]+1]=int(name[index[0]+1])-32;
			cout<<name[index[0]+1];
			for(unsigned int i=index[0]+2;i<strlen(name);i++){
				if(name[i]>=65&&name[i]<=90)
					name[i]=int(name[i])+32;
				cout<<name[i];
			}
			cout<<endl;
		}
		else if(count==2){
			if(name[0]>=97&&name[0]<=122)
				name[0]=int(name[0])-32;
			cout<<name[0]<<". ";
			if(name[index[0]+1]>=97&&name[index[0]+1]<=122)
				name[index[0]+1]=int(name[index[0]+1])-32;
			cout<<name[index[0]+1]<<". ";
			if(name[index[1]+1]>=97&&name[index[1]+1]<=122)
				name[index[1]+1]=int(name[index[1]+1])-32;
			cout<<name[index[1]+1];
			for(unsigned int i=index[1]+2;i<strlen(name);i++){
				if(name[i]>=65&&name[i]<=90)
					name[i]=int(name[i])+32;
				cout<<name[i];
			}
			cout<<endl;
		}
	}
			
	return 0;
}
