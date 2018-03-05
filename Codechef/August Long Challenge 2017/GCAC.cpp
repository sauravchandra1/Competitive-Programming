#include<bits/stdc++.h>
using namespace std;
 
struct companydata{
 
	int offeredsalary;
	int maxjoboffer;
	int prepos;
};
 
bool compare(companydata a, companydata b){
 
	return(a.offeredsalary<b.offeredsalary);
}
 
int main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int test;
	cin>>test;
 
	while(test--){
 
		int n,m;
		cin>>n>>m;
 
		int* minsalary=new int[n];
		long long int totalsalary=0,totalcandidate=0,totalcompany=0;
		int lookup[1100];
		memset(lookup,0,1100*sizeof(lookup[0]));
		companydata* data=new companydata[m];
		vector<string> qual;
		string str;
 
		for(int i=0;i<n;i++)
			cin>>minsalary[i];
		
		for(int i=0;i<m;i++){
 
			cin>>data[i].offeredsalary;
			cin>>data[i].maxjoboffer;
			data[i].prepos=i;
		}
 
		sort(data,data+m,compare);
 
		for(int i=0;i<n;i++){
 
			cin>>str;
			qual.push_back(str);
		}
 
		int temppos=0,tempjo=0,tempms=0,tempos=0;
 
		for(int i=0;i<n;i++){
 
			str=qual[i];
			tempms=minsalary[i];
 
			for(int j=m-1;j>=0;j--){
 
				tempos=data[j].offeredsalary;
				tempjo=data[j].maxjoboffer;
				temppos=data[j].prepos;
 
				if(tempjo<=0)
					continue;
 
				if(tempos<tempms)
					break;
 
				if((int(str[temppos])-48)&&(tempos>=tempms)){
 
					lookup[temppos]=1;
					totalcandidate++;
					totalsalary+=tempos;
					data[j].maxjoboffer--;
					break;
				}
 
			}
		}
 
		for(int i=0;i<1100;i++){
 
			if(lookup[i]==1)
				totalcompany++;
		}
 
		cout<<totalcandidate<<" "<<totalsalary<<" "<<m-totalcompany<<endl;
 
	}
 
	return 0;
}
 
