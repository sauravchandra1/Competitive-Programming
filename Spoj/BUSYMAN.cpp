#include <bits/stdc++.h>
using namespace std;

#define N 100005

struct data{
	int L,R;
};

data arr[N];

bool cmp(data a,data b){
	if(a.R==b.R)
		return a.L<b.L;
	else
		return a.R<b.R;
}
		
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int num;
		scanf("%d",&num);
		for(int i=0;i<num;i++)
			scanf("%d %d",&arr[i].L,&arr[i].R);
		sort(arr,arr+num,cmp);
		int ans=0,end=-1;		
		for(int i=0;i<num;i++){
			if(arr[i].L>=end){
				ans++;
				end=arr[i].R;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
