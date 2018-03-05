#include <bits/stdc++.h>
using namespace std;

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int max1=0,max2=0;
		int n,m,x;
		scanf("%d%d",&n,&m);	
		for(int i=0;i<n;i++){
			scanf("%d",&x);		
			if(x>max1)
				max1=x;
		}
		for(int i=0;i<m;i++){
			scanf("%d",&x);	
			if(x>max2)
				max2=x;
		}
		if(max1>=max2)
			printf("Godzilla\n");
		else
			printf("MechaGodzilla\n");
	}
	return 0;
}
