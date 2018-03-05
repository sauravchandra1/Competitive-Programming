#include<bits/stdc++.h>
using namespace std;
 
int main(){
 
	int test;
	cin>>test;
 
	while(test--){
 
		string s,t;
		cin>>s;
		cin>>t;
 
		int svalue[200];
		int tvalue[200];
		memset(svalue,0,200*sizeof(svalue[0]));
		memset(tvalue,0,200*sizeof(tvalue[0]));
 
		for(unsigned int i=0;i<s.length();i++){
 
			svalue[int(s[i])]++;
			tvalue[int(t[i])]++;
		}
 
		int x=0;
 
		for(int i=90;i<=130;i++){
 
			if((svalue[i]>=2)&&(tvalue[i]==0)){
 
				cout<<"A"<<endl;
				x=1;
				break;
			}
		}
 
		if(x==1)
			continue;
 
		for(int i=90;i<=130;i++){
 
			if(tvalue[i]>0){
 
				if(svalue[i]==0){
 
					cout<<"B"<<endl;
					x=1;
					break;
				}
			}
		}
 
		if(x==1)
			continue;
 
		for(int i=90;i<=130;i++){
 
			if(svalue[i]>0){
 
				if(tvalue[i]==0){
 
					cout<<"A"<<endl;
					x=1;
					break;
				}
			}
		}
 
		if(x==1)
			continue;
 
		cout<<"B"<<endl;
 
	}
 
	return 0;
}
 
