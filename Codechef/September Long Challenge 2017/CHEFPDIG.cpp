#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		string s;
		cin>>s;
		int arr[100];
		memset(arr,0,100*sizeof(arr[0]));
		int final_arr[100];
		memset(final_arr,0,100*sizeof(final_arr[0]));
		for(unsigned int i=0;i<s.size();i++)
			arr[int(s[i])-48]++;
		int flag1=0,flag2=0,flag=0;
		for(int i=65;i<=90;i++){
			if(i==66||i==77||i==88){
				flag=i%10;
				if(arr[flag]>=2)
					final_arr[i]=1;
			}
			else{
				flag=i;
				flag1=i%10;
				flag/=10;
				if(arr[flag]>=1&&arr[flag1]>=1)
					final_arr[i]=1;
			}
		}
		for(int i=65;i<=90;i++)
			if(final_arr[i]==1)
				printf("%c",char(i));
		printf("\n");
	}
	return 0;
} 
