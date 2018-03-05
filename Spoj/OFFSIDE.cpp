#include <bits/stdc++.h>
using namespace std;

int main(){
	while(true){
		int num1=0,num2=0;
		scanf("%d%d",&num1,&num2);
		if(num1==0&&num2==0)
			break;
		int* at=new int[num1];
		int* dif=new int[num2];
		for(int i=0;i<num1;i++)
			scanf("%d",&at[i]);	
		for(int i=0;i<num2;i++)
			scanf("%d",&dif[i]);
		sort(at,at+num1);
		sort(dif,dif+num2);
		if(dif[1]<=at[0])
			printf("N\n");
		else 
			printf("Y\n");
	}
	return 0;
}
