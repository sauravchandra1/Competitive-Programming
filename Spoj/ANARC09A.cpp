#include <bits/stdc++.h>
using namespace std;

int main(){
	int count=0;
	while(true){
		count++;
		string str;
		stack<char> con;
		cin>>str;
		if(str[0]=='-')	
			break;
		else{
			int cnt=0;
			for(int i=0;i<str.size();i++){
				if(str[i]=='{')
					con.push('{');
				else{
					if(!con.empty())
						con.pop();
					else{
						cnt++;
						con.push('}');
					}
				}
			}
			int ans=cnt+(con.size()/2);
			printf("%d. %d\n",count,ans);
		}
	}
	return 0;
}

