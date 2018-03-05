#include <bits/stdc++.h>
using namespace std;

int main(){
	int num;
	scanf("%d",&num);
	int tbf=0,obt=0,obf=0;
	string temp;
	for(int i=0;i<num;i++){
		cin>>temp;
		if(temp[0]=='1'&&temp[2]=='2')
			obt++;
		else if(temp[0]=='3'&&temp[2]=='4')
			tbf++;
		else 
			obf++;
	}
	int ans=0;
	if(tbf>=obf){
		ans+=tbf;
		obf=0;
	}
	else {
		ans+=tbf;
		obf-=tbf;
	}
	if(obt%2==0||obt==0)
		ans+=obt/2;
	else{
		ans+=obt/2+1;
		if(obf==1)
			obf-=1;
		else if(obf>=2)
			obf-=2;
	}
	if(obf%4==0||obf==0)
		ans+=obf/4;
	else 
		ans+=obf/4+1;
	printf("%d\n",ans+1);
	return 0;
}	
