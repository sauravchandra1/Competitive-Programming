#include <bits/stdc++.h>
using namespace std;

int main(){
	while(1){
		int num;
		scanf("%d",&num);
		if(num==0)
			break;
		int cnt=0;
		while(num!=0){
			num=num>>1;
			cnt++;
		}
		printf("%d\n",cnt-1);
	}
	return 0;
}
