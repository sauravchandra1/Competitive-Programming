#include <bits/stdc++.h>
using namespace std;

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		double a,b,c,d;
		scanf("%lf %lf %lf %lf",&a,&b,&c,&d);	
		double s=(a+b+c+d)/2;
		double ans=(s-a)*(s-b)*(s-c)*(s-d);
		double answer=sqrt(ans);
		printf("%.2lf\n",answer);
	}
	return 0;
}
