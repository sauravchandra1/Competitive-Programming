#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	while(1){
		string str;
		cin>>str;
		if(str[0]=='0')
			return 0;
		ll ans[50005];
		memset(ans,0,sizeof ans);
		ans[0]=1;	
		ans[1]=1;
		int flag=0;
		int a=int(str[0]-'0'),b=0;
		for(unsigned int i=1;i<str.size();i++){
			b=int(str[i]-'0');
			if(b==0){
				if(a==1||a==2)
					ans[i+1]=ans[i-1];
				else{
					printf("0\n");
					flag=1;
					break;
				}
			}
			else if((a*10+b)<=26&&(a*10+b>=10))
				ans[i+1]=ans[i]+ans[i-1];
			else
				ans[i+1]=ans[i];	
			a=b;	
		}
		if(flag==0)
		printf("%lld\n",ans[str.size()]);
	}
	return 0;
}
