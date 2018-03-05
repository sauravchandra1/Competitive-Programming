#include<bits/stdc++.h>
using namespace std;
int main(){
	int test;
	cin>>test;
	
	cin.ignore();
	while(test--){
		
		string str;
		getline(cin,str);
		
		long long int arr[100000];
		long long int x=0,y=0,j=0;
		unsigned int i=0;
		
		for(i=0;i<str.size();i++){
			x=0,y=0;
			while(str[i]!=' '&&i<str.size()){
				x=int(str[i])-48;
				y=10*y+x;
				i++;
			}
			arr[j]=y;
			j++;
		}
		
		int mx=-1;
		int num=0,z=0;
		int len=j-1;
		for(unsigned int i=0;i<j;i++){
			
			num=arr[i];
			
			if(z==1){
				if(num>mx)
					mx=num;
			}
			else if((z==0)&&(num!=len)){
				if(num>mx)
					mx=num;
			}
			if(num==len)
				z=1;
		}
		cout<<mx<<endl;
	}
	return 0;
}
