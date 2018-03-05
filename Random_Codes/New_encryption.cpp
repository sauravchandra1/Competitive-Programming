#include<iostream>
#include<string.h>
using namespace std;

int main(){
	
	cout<<"Enter Your Name: ";


	char username[30];
	cin.getline(username,30);
	
	
	cout<<"Enter Your Code: ";

	int code;
	cin>>code;
	

	int username_length=strlen(username);
	
	int temp;
	for(int i=0;i<username_length;i++){

		if(username[i]!=' '){

			if(username[i]>=65&&username[i]<=90){
				
				temp=(int(username[i])-64+code)%26;
				if(temp==0)
					username[i]=90;
				else
					username[i]=temp+64;
			}
			else if(username[i]>=97&&username[i]<=122){
					
				temp=(int(username[i])-96+code)%26;
					if(temp==0)
						username[i]=122;
					else
						username[i]=temp+96;
			}
		}
	}

	cout<<"Your Enctyption Is: ";

	for(int i=0;i<username_length;i++)
		cout<<username[i];

	cout<<endl;

	cout<<"Your Code Is: ";

	int count=0;

	int c=code;
	while(c!=0){
		c/=10;
		count++;
	}

	int newcount=4-count;
	while(newcount--){
		cout<<"0";
	}
	cout<<code;

	cout<<endl;
	return 0;
}
