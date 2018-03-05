#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const int siz=1e5+5;

#define pb push_back

int main(){
	int n;
	scanf("%d",&n);
	vector<int> v[siz],check;
	int chk[siz];
	memset(chk,0,siz*sizeof(chk[0]));
	int x,y;
	for(int i=0;i<n-1;i++){
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
		if(chk[x]==0){
			check.pb(x);
			chk[x]=1;
		}
		if(chk[y]==0){
			check.pb(y);
			chk[y]=1;
		}
	}
	int arr[siz];
	int mark[siz];
	memset(arr,0,siz*sizeof(arr[0]));
	memset(mark,0,siz*sizeof(mark[0]));
	arr[x]=1;
	mark[x]=1;
	queue<int> q;
	for(int i=0;i<v[x].size();i++){
		q.push(v[x][i]);
		mark[v[x][i]]=2;
	}
	int temp=0,group=2;
	while(!q.empty()){
		temp=q.front();
		if(mark[temp]==1)
			group=2;
		else
			group=1;
		q.pop();
		for(int i=0;i<v[temp].size();i++){
			if(arr[v[temp][i]]==0){
				q.push(v[temp][i]);
				mark[v[temp][i]]=group;
			}
			arr[temp]=1;
		}
	}
	int g1=0,g2=0;
	for(int i=0;i<siz;i++){
		if(mark[i]==1)
			g1++;
		else if(mark[i]==2)
			g2++;
	}
	ll ans=0;
	for(int i=0;i<check.size();i++){
		group=mark[check[i]];
		if(group==1){
			ans+=g2-v[check[i]].size();
		}
		else{
			ans+=g1-v[check[i]].size();
		}
	}
	printf("%lld\n",ans/2);
	return 0;
}
