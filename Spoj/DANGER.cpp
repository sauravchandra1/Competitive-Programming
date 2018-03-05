#include <bits/stdc++.h>
using namespace std;

int find_num(string str){
	int num=(str[1]-'0'+(str[0]-'0')*10)*pow(10,str[3]-'0');
	return num;
}

int main(){
	while(1){
		string str;
		cin>>str;
		int num;
		if(str=="00e0")
			break;
		else 
			num=find_num(str);
		int pwr=int(floor(log(num)/log(2)));
		int two_pow=pow(2,pwr);
		int ans=2*(num-two_pow)+1;
		printf("%d\n",ans);
	}
	return 0;
}
