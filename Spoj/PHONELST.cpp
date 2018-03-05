#include <bits/stdc++.h>
using namespace std;

struct trie{
	trie *next[10];
	bool end;
	trie(){
		for(int i=0;i<10;i++)
			next[i]=NULL;
		end=0;
		
	}
};

int main(){
	int test;
	scanf("%d",&test);
	string str;
	int flag=0,temp=0;
	int num;
	while(test--){	
		trie *root=new trie,*link=NULL;	
		flag=0,temp=0;
		scanf("%d",&num);
		for(int i=0;i<num;i++){
			cin>>str;
			if(flag==0){
				link=root;
				for(int i=0;i<str.size();i++){
					if(link->end==1){
						flag=1;
						break;
					}
					temp=str[i]-'0';
					if(link->next[temp]==NULL)
						link->next[temp]=new trie;
					link=link->next[temp];
				}
				link->end=1;
				for(int i=0;i<10;i++){
					if(link->next[i]){
						flag=1;
						break;
					}
				}
			}
		}
		if(flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}	
