#include <cstdio>
#include <algorithm>

using namespace std;

#define block 555
#define N 300005
#define siz 1000006

int cnt[siz],arr[N],ans=0,sol[N];

struct node{
	int L,R,pos;
}query[N];

bool cmp(node x,node y){
	if(x.L/block!=y.L/block)
		return x.L/block<y.L/block;
	else
		return x.R<y.R;
}
		
void add(int pos){
	cnt[arr[pos]]++;
	if(cnt[arr[pos]]==1)
		ans++;
}

void remove(int pos){
	cnt[arr[pos]]--;	
	if(cnt[arr[pos]]==0)
		ans--;
}


int main(){
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
		scanf("%d",&arr[i]);
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d %d",&query[i].L,&query[i].R);
		query[i].pos=i;
	}
	sort(query,query+q,cmp);
	int curr_L=0,curr_R=0;	
	ans=1;
	cnt[arr[0]]++;
	for(int i=0;i<q;i++){
		int L=query[i].L-1,R=query[i].R-1;
		while(curr_L<L){
			remove(curr_L);
			curr_L++;
		}
		while(curr_L>L){
			add(curr_L-1);
			curr_L--;
		}
		while(curr_R<R){
			add(curr_R+1);
			curr_R++;
		}
		while(curr_R>R){
			remove(curr_R);
			curr_R--;
		}
		sol[query[i].pos]=ans;
	}
	for(int i=0;i<q;i++)
		printf("%d\n",sol[i]);
	return 0;
}
