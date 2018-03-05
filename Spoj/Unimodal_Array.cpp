#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int x=0,ans=0,j=1;
	for(int i=0;i<n-1;i++){
		if(j<n){
			if(a[i]<a[j]){
				if(ans==0)
					ans=1;
				x=1;
				j++;
			}
			else if(a[i]==a[j]){
				if(ans==0)
					ans=2;
				x=2;
				j++;
			}
			else if(a[i]>a[j]){
				if(ans==0)
					ans=3;
				x=3;
				j++;
			}
			if(ans>x){
				ans=4;
				cout<<"NO"<<endl;
				break;
			}
			else
				ans=x;
		}
	}
	if(ans!=4)
		cout<<"YES"<<endl;
	return 0;
}
