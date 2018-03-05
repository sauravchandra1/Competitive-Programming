#include <bits/stdc++.h>
using namespace std;

#define N 100005

typedef long long ll;
ll mx;
ll arr[N];

int main(){
	while(1){
		mx=-1;
		stack<ll> con;
		ll i=0,num,area=0,height;
		scanf("%lld",&num);
		if(num==0)
			return 0;
		for(i=0;i<num;i++)
			scanf("%lld",&arr[i]);
		for(i=0;i<num;i++){
			while(!con.empty()&&arr[i]<arr[con.top()]){
				height=arr[con.top()];
				con.pop();
				if(!con.empty())
					area=height*(i-con.top()-1);
				else
					area=height*i;
				if(area>mx)
					mx=area;
			}
			con.push(i);
		}
		while(!con.empty()){
				height=arr[con.top()];
				con.pop();
				if(!con.empty())
					area=height*(i-con.top()-1);
				else
					area=height*i;
				if(area>mx)
					mx=area;
		}
		printf("%lld\n",mx);
	}
	return 0;
}
