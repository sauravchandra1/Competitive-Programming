#include <bits/stdc++.h>
using namespace std;

const int siz=1e5+5;

int per[siz];
int amb[siz];

int main(){
	while(1){
		int n,flag=0;
		scanf("%d",&n);
		if(n==0)
			break;
		for(int i=1;i<=n;i++){
			scanf("%d",&per[i]);		
			amb[per[i]]=i;
		}
		for(int i=1;i<=n;i++){
			if(per[i]!=amb[i]){
				printf("not ambiguous\n");
				flag=1;
				break;
			}
		}
		if(flag==0)
			printf("ambiguous\n");
	}
	return 0;
}
