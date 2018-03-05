#include <bits/stdc++.h>
using namespace std;

vector<int> arr,con1,con2;
int ind1,ind2;

#define pb push_back

int main(){
	int num;
	scanf("%d",&num);
	int temp;
	for(int i=0;i<num;i++){
		scanf("%d",&temp);
		arr.pb(temp);
	}
	for(int i=0;i<num;i++){
		for(int j=0;j<num;j++){
			for(int k=0;k<num;k++){
				temp=(arr[i]*arr[j])+arr[k];
				con1.pb(temp);
			}
		}
	}	
	for(int i=0;i<num;i++){
		for(int j=0;j<num;j++){
			for(int k=0;k<num;k++){
				if(arr[k]==0)
					continue;
				temp=(arr[i]+arr[j])*arr[k];
				con2.pb(temp);
			}
		}
	}
	sort(con1.begin(),con1.end());
	sort(con2.begin(),con2.end());
	long long ans=0;
	for(int i=0;i<con1.size();i++){
		ind1=lower_bound(con2.begin(),con2.end(),con1[i])-con2.begin();
		ind2=upper_bound(con2.begin(),con2.end(),con1[i])-con2.begin();
		ans+=ind2-ind1;
	}
	printf("%lld\n",ans);	
	return 0;
}
	
