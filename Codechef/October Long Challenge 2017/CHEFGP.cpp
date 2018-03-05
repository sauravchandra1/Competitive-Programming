#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		string str;
		cin>>str;
		int lim_a,lim_b;
		scanf("%d %d",&lim_a,&lim_b);
		int cnt_a=0,cnt_b=0;
		for(int i=0;i<str.size();i++){
			if(str[i]=='a')
				cnt_a++;
			else 
				cnt_b++;
		}
		int more=0,less=0,limit=0;
		char m_ch,l_ch;
		if(cnt_a>cnt_b){
			more=cnt_a;
			less=cnt_b;
			m_ch='a';
			l_ch='b';
			limit=lim_a;
		}
		else{
			more=cnt_b;
			less=cnt_a;
			m_ch='b';
			l_ch='a';
			limit=lim_b;
		}
		if(less==0){
			int flag=0;
			while(1){
				for(int i=0;i<limit;i++){
					printf("%c",m_ch);
					more--;
					if(more==0){
						flag=1;
						break;
					}
				}
				if(flag==0)	
					printf("*");
				else 
					break;
			}
		}
		else{
			int div=more/less;
			int rem=more%less;
			if(limit>div){
				for(int i=0;i<rem;i++){
					for(int j=0;j<div+1;j++)
						printf("%c",m_ch);		
					printf("%c",l_ch);
					less--;
				}
				for(int i=0;i<less;i++){
					for(int j=0;j<div;j++)
						printf("%c",m_ch);
					printf("%c",l_ch);
				}
					
			}
			else{
				int flag=0;
				for(int i=0;i<less;i++){
					for(int j=0;j<limit;j++)
						printf("%c",m_ch);
					printf("%c",l_ch);
				}
				int temp=more-less*limit;
				if(temp!=0){
					while(1){
						for(int i=0;i<limit;i++){
							printf("%c",m_ch);
							temp--;
							if(temp==0){
								flag=1;
								break;
							}
						}
						if(flag==0)
							printf("*");
						else 
							break;
					}
				}
			}											
		}
		printf("\n");
	}
	return 0;
}
			
