#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool check(string exp) {
	stack <char> s;
	for(unsigned int i=0;i<exp.length();i++){
		if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
			s.push(exp[i]);
		else if(!(s.empty())){	
			if(((s.top()=='(')&&(exp[i]==')'))||((s.top()=='{')&&(exp[i]=='}'))||((s.top()=='[')&&(exp[i]==']')))
				s.pop();
			else 
				return false;
		}
		
	}
	return s.empty() ? true:false;
}
int main(){
	string exp;
	cin>>exp;
	if(check(exp))
		cout<<"Parantheses Balanced"<<endl;
	else
		cout<<"Parantheses Not Balanced"<<endl;
}
