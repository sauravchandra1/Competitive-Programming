#include<iostream>
#include<string.h>
using namespace std;
int main(){                                                                                                                                                                                                                                                                                                                                                                                               
	int test;
	//cout<<"Enter Test Case :"<<endl;
	cin>>test;
	while(test--){
		//cout<<"Enter First String :"<<endl;
		int n, m;
		cin >> n >> m;
		char string1[6000];
		cin>>string1;
		//cout<<"Enter Second String :"<<endl;
		char string2[6000];
		cin>>string2;
		int string_length1=strlen(string1)+1;
		int string_length2=strlen(string2)+1;
		int table[string_length1][string_length2];
		for(int i=0;i<string_length1;i++){
			table[i][0]=0;
		}
		for(int i=0;i<string_length2;i++){
			table[0][i]=0;
		}
		for(int i=1;i<string_length1;i++){
			for(int j=1;j<string_length2;j++){
				if(string1[i-1]==string2[j-1])
					table[i][j]=table[i-1][j-1]+1;
				else
					table[i][j]=max(table[i-1][j],table[i][j-1]);
			}
		}
		//cout<<"The Length of Longest Common Subsequence is :";
		cout<<(n + m - 2  * table[string_length1-1][string_length2-1]) + table[string_length1-1][string_length2-1]<<endl;
	}
	return 0;
}