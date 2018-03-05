#include <bits/stdc++.h>
using namespace std;

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		map<string,int> mp;
		map<string,int>::iterator it;
		string str;
		int num;
		scanf("%d\n",&num);
		for(int i=0;i<num;i++){
			getline(cin,str);
			mp[str]++;
		}
		for(it=mp.begin();it!=mp.end();it++)
			printf("%s %d\n",(*it).first.c_str(),(*it).second);
		printf("\n");
	}
	return 0;
}
		
