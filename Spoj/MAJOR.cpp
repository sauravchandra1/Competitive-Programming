#include <bits/stdc++.h>
using namespace std;

int pos[1005];
int neg[1005];

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		memset(pos,0,sizeof pos);
		memset(neg,0,sizeof neg);
		int num;
		scanf("%d",&num);
		int check=num/2+1;
		int temp;
		for(int i=0;i<num;i++){
			scanf("%d",&temp);
			if(temp>=0)
				pos[temp]++;
			else
				neg[-temp]++;
		}
		int flag=0;
		for(int i=0;i<1005;i++){
			if(pos[i]>=check){
				printf("YES %d\n",i);
				flag=1;
				break;
			}
		}
		if(flag==0){
			for(int i=0;i<1005;i++){
				if(neg[i]>=check){
					printf("YES -%d\n",i);
					flag=1;
					break;
				}
			}
		}
		if(flag==0)
			printf("NO\n");
	}
	return 0;
}
