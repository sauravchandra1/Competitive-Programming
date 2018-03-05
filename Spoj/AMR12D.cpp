#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		string str1,str2;
		cin>>str1;
		str2=str1;
		reverse(str2.begin(),str2.end());
		if(str2==str1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
		
