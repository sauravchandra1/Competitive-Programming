#include <bits/stdc++.h>
using namespace std;

int main(){
	int test;
	scanf("%d\n",&test);
	while(test--){
		char a[100],b[100],ans[100];
		scanf("%s + %s = %s",a,b,ans);
		int num1=0,num2=0,num3=0,flag=0;
		for(int i=0;i<strlen(a);i++){
			if(int(a[i])<60)
				num1=num1*10+(int(a[i])-48);
			else{
				flag=1;
				break;
			}
		}
		for(int i=0;i<strlen(b);i++){
			if(int(b[i])<60)
				num2=num2*10+(int(b[i])-48);
			else{
				flag=2;
				break;
			}
		}
		for(int i=0;i<strlen(ans);i++){
			if(int(ans[i])<60)
				num3=num3*10+(int(ans[i])-48);
			else{
				flag=3;
				break;
			}
		}
		if(flag==1)
			printf("%d + %d = %d\n",num3-num2,num2,num3);
		else if(flag==2)
			printf("%d + %d = %d\n",num1,num3-num1,num3);
		else
			printf("%d + %d = %d\n",num1,num2,num1+num2);
	}
	return 0;
}