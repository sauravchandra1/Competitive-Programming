#include <bits/stdc++.h>
using namespace std;

int reverse(int n){
	int x=0,y=0;
	while(n!=0){
		x=n%10;
		y=10*y+x;
		n/=10;
	}
	return y;
}
int main(){
	while(1){
		int n,m;
		scanf("%d",&n);
		m=reverse(n);	
		if(n==m)
			n++;
		while(1){
			m=reverse(n);
			if(n==m){
				printf("%d\n",n);
				break;
			}
			n++;
		}
	}
	return 0;
}
			
