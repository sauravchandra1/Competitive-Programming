#include <bits/stdc++.h>
using namespace std;

int arr1[140];
int arr2[140];

int main(){	
	string s1,s2;
	while(cin>>s1){
		memset(arr1,0,sizeof arr1);
		memset(arr2,0,sizeof arr2);
		cin>>s2;
		for(int i=0;i<s1.size();i++)
			arr1[s1[i]]++;
		for(int i=0;i<s2.size();i++)
			arr2[s2[i]]++;
		int mn;
		for(int i=0;i<130;i++)
			if(arr1[i]!=0&&arr2[i]!=0){
				mn=min(arr1[i],arr2[i]);
				while(mn--)
					printf("%c",char(i));
			}
		printf("\n");
	}
	return 0;
}
