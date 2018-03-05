#include<bits/stdc++.h>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--){
		string s;
		cin>>s;
		stack <char> stk;
		for(int i=0;i<s.length();i++){
			if(s[i]=='(');
			else if(s[i]>='a'&&s[i]<='z')
				cout<<s[i];
			else if(s[i]==')'){
				cout<<stk.top();
				stk.pop();
			}
			else 
				stk.push(s[i]);
		}
		cout<<endl;
	}
	return 0;
}