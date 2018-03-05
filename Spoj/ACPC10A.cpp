#include <bits/stdc++.h>
using namespace std;

int main(){

	while(1){

		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);

		if(x==0&&y==0&&z==0)
			break;

		if(x==0&&y==0||y==0&&z==0||z==0&&x==0)
			printf("GP 0\n");
		else if(z-y==y-x)
			printf("AP %d\n",(y-x)+z);
		else if(z%y==0&&y%x==0)
			printf("GP %d\n",(y/x)*z);

	}
	return 0;
}