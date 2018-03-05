#include <bits/stdc++.h>
using namespace std;

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		double u,U,v,V,w,W,a,ans=0;
		scanf("%lf %lf %lf %lf %lf %lf",&u,&v,&w,&W,&V,&U);
		a=4*(pow(u,2)*pow(v,2)*pow(w,2)) 
           	-pow(u,2)*pow((pow(v,2)+pow(w,2)-pow(U,2)),2) 
           	-pow(v,2)*pow((pow(w,2)+pow(u,2)-pow(V,2)),2) 
           	-pow(w,2)*pow((pow(u,2)+pow(v,2)-pow(W,2)),2) 
           	+(
              	pow(v,2)+pow(w,2)-pow(U,2))*
              	(pow(w,2)+pow(u,2)-pow(V,2))*
              	(pow(u,2)+pow(v,2)-pow(W,2)
             	);
		ans=sqrt(a);
		ans/=12;
		printf("%.4lf\n",ans);
	}
	return 0;
}
