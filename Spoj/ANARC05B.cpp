#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int siz=1e4+5;
vector<int> arr1,arr2;
int ind1[siz],ind2[siz],low,high;
ll sum1[siz],sum2[siz];

int main(){
	while(1){
		memset(sum1,0,sizeof sum1);
		memset(sum2,0,sizeof sum2);
		memset(ind1,0,sizeof ind1);
		memset(ind2,0,sizeof ind2);
		arr1.clear(),arr2.clear();
		int num1,num2,temp;
		scanf("%d",&num1);
		if(num1==0)
			break;
		for(int i=0;i<num1;i++){
			scanf("%d",&temp);
			arr1.push_back(temp);
		}
		arr1.push_back(siz);
		scanf("%d",&num2);
		for(int i=0;i<num2;i++){
			scanf("%d",&temp);
			arr2.push_back(temp);
		}
		arr2.push_back(siz);
		sum1[0]=0,sum2[0]=0;
		for(int i=1;i<=num1+1;i++)
			sum1[i]=arr1[i-1]+sum1[i-1];
		for(int i=1;i<=num2+1;i++)
			sum2[i]=arr2[i-1]+sum2[i-1];
		int j=0,count=0;
		for(int i=0;i<=num1;i++){
			low=lower_bound(arr2.begin(),arr2.end(),arr1[i])-arr2.begin();
			if(arr2[low]==arr1[i]){
				ind1[j]=i;
				ind2[j]=low;
				count++;
				j++;
			}
		}
		ll last1=0,last2=0,sim1,sim2;
		ll ans=0;
		for(int i=0;i<count;i++){
			sim1=ind1[i]+1;
			sim2=ind2[i]+1;
			if(sum1[sim1]-last1>sum2[sim2]-last2)
				ans+=sum1[sim1]-last1;
			else
				ans+=sum2[sim2]-last2;
			last1=sum1[sim1];
			last2=sum2[sim2];
		}
		printf("%lld\n",ans-siz);			
	}
	return 0;
}
