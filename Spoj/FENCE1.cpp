#include <bits/stdc++.h>
using namespace std;

const long double PI = 3.141592653589793238L;

int main(){
	while(1){
		double L;
		scanf("%lf",&L);
		if(L==0)
			break;
		double ans=(L*L)/(2*PI);
		printf("%.2f\n",ans);
	}
	return 0;
}
