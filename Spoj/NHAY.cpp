#include <bits/stdc++.h>
using namespace std;

string pat,txt;

void cmp_lps(int lps[],int pat_len){
	int len=0;
	lps[0]=0;
	int i=1;
	while(i<pat_len){
		if(pat[i]==pat[len]){
			len++;
			lps[i]=len;
			i++;
		}
		else{
			if(len!=0)
				len=lps[len-1];
			else{
				lps[i]=0;
				i++;
			}
		}
	}
}

void kmp(){
	int flag=0;
	int pat_len=pat.size();
	int txt_len=txt.size();
	int* lps=new int[pat_len+1];
	cmp_lps(lps,pat_len);
	int i=0,j=0;
	while(i<txt_len){
		if(pat[j]==txt[i]){
			j++;
			i++;
		}
		if(j==pat_len){
			flag=1;
			cout<<i-j<<endl;
			j=lps[j-1];
		}
		else if(i<txt_len&&pat[j]!=txt[i]){
			if(j!=0)
				j=lps[j-1];
			else 
				i++;
		}
	}
	if(flag==0)
		cout<<endl;
}
	
int main(){
	std::ios_base::sync_with_stdio(false);
	int len;
	while(cin>>len){
		cin>>pat;
		cin>>txt;
		kmp();	
	}
	return 0;
}
