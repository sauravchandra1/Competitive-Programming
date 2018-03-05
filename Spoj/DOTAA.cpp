#include <bits/stdc++.h>
using namespace std;

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int hero,tow,dam;
		scanf("%d %d %d",&hero,&tow,&dam);
		int ans=0,temp;
		for(int i=0;i<hero;i++){
			scanf("%d",&temp);
			ans+=temp/dam;
			if(temp%dam==0)
				ans--;
		}
		if(ans>=tow)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
