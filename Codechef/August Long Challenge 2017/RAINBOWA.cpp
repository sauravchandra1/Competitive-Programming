#include<bits/stdc++.h>
using namespace std;
 
int main(){
 
	int test;
	cin>>test;
 
	while(test--){
 
		int n;
		cin>>n;
 
		int* arr=new int[n];
 
		for(int i=0;i<n;i++)
			cin>>arr[i];
 
		if(n%2==0){
 
			int div=n/2-1,x=0;
 
			for(int i=0;i<div;i++){
 
				if(arr[i]!=arr[n-1-i]){
					cout<<"no"<<endl;
					x=1;
					break;
				}
			}
 
			if(x==1)
				continue;
 
			int current=1;
 
			if(arr[0]!=1||arr[div]!=7){
				cout<<"no"<<endl;
				continue;
			}
 
			for(int i=0;i<div;i++){
 
				if(arr[i]==current)
					continue;
				else if(arr[i]==current+1){
					current++;
				}
				else{
					cout<<"no"<<endl;
					x=1;
					break;
				}
			}
 
			if(x==1)
				continue;
 
			cout<<"yes"<<endl;
 
		}
		else{
 
			int div=n/2-1,x=0;
 
			for(int i=0;i<div;i++){
 
				if(arr[i]!=arr[n-1-i]){
					cout<<"no"<<endl;
					x=1;
					break;
				}
			}
 
			if(x==1)
				continue;
 
			int current=1;
 
			if((arr[0]!=1)||(arr[div+1]!=7)){
				cout<<"no"<<endl;
				continue;
			}
 
			for(int i=0;i<div;i++){
 
				if(arr[i]==current)
					continue;
				else if(arr[i]==current+1){
					current++;
				}
				else{
					cout<<"no"<<endl;
					x=1;
					break;
				}
			}
 
			if(x==1)
				continue;
 
			if(arr[div]==6||arr[div]==7)
			cout<<"yes"<<endl;
 
		}
	}
	return 0;
} 
