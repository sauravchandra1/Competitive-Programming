#include <bits/stdc++.h>
using namespace std;

const int siz=1e5+5;

int arr[siz];
int ans[siz];

int main(){
	int n,query=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int temp=0;
	for(int i=0;i<n;i++){
		temp=arr[i];
		for(int j=1;j<=sqrt(temp);j++){
			if(temp%j==0){
				if((temp/j)==j)
					ans[j]++;
				else{ 
					ans[j]++;
					ans[(temp/j)]++;
				}
			}
		}
	}
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d",&query);
		printf("%d\n",ans[query]);
	}	
	return 0;
}
		
	
