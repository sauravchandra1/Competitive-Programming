#include <bits/stdc++.h>
using namespace std;

int main(){
	while(true){
		int girl,boy;
		scanf("%d%d",&girl,&boy);
		if(girl==-1&&boy==-1)
			break;
		if(girl<boy)
			swap(girl,boy);
		float a=girl,b=boy+1;
		int ans=ceil(a/b);
		printf("%d\n",ans);
	}
	return 0;
}
