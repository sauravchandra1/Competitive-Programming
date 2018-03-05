#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll mod=1e9+7;
 
vector<int> v;
int lookup[200][200][100];
 
int dfs(vector<int> v,unsigned int current,bool check1,bool check2,int temp){ 
	
	int ans=1;
	
	if(check1==true){
		
		if(check2==true){
			
			v[current]=v[current]-temp;
			v[current+1]+=temp;
		}
		else{
			
			v[current]=v[current]-temp;
			v[current+1]=temp;
			v.push_back(0);
		}
	}
		
	
	if(current==v.size()-2){
	
		return ans%mod;
	}
	else{
			
		int minimum=min(v[current],v[current+1]);
		
		if(current==v.size()-3&&minimum==0){
			
			return ans%mod;
		}
		else{	
					  
			for(int i=0;i<=minimum;i++){
	 
				if(i==0){
					
					if(current+3<v.size()){
											
						if(lookup[v[current+1]][v[current+2]][current+1]!=0)	
							ans=lookup[v[current+1]][v[current+2]][current+1]%mod;
						else{
							
							lookup[v[current+1]][v[current+2]][current+1]=dfs(v,current+1,false,false,0)%mod;
							ans=lookup[v[current+1]][v[current+2]][current+1]%mod;
						}							
					}
					else
						ans=dfs(v,current+1,false,false,0)%mod;
				}
				else if((current+3)==v.size()){
					
					if(lookup[v[current+1]-i][i][current+1]!=0)
						ans=(ans+lookup[v[current+1]-i][i][current+1])%mod;
					else{
					
						lookup[v[current+1]-i][i][current+1]=dfs(v,current+1,true,false,i)%mod;
						ans=(ans+lookup[v[current+1]-i][i][current+1])%mod;
					}					
				}
				else{
					
					if(lookup[v[current+1]-i][v[current+2]+i][current+1]!=0)
						ans=(ans+lookup[v[current+1]-i][v[current+2]+i][current+1])%mod;
					else{
						
						lookup[v[current+1]-i][v[current+2]+i][current+1]=dfs(v,current+1,true,true,i)%mod;
						ans=(ans+lookup[v[current+1]-i][v[current+2]+i][current+1])%mod;
					}
				}
			}
		}
	}
	
	return ans%mod;
}
 
int main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int test;
	cin>>test;
 
	while(test--){
 
		v.clear();
		
		for(int i=0;i<200;i++){
			
			for(int j=0;j<200;j++){
				
				for(int k=0;k<100;k++){
					
					lookup[i][j][k]=0;
				}
			}
		}
 
		int n;
		cin>>n;
 
		int x;
 
		for(int i=0;i<n;i++){
 
			cin>>x;
			v.push_back(x);
		}
		
		
		v.push_back(0);
		
		
		unsigned int current=0;
		
		int ans=dfs(v,current,false,false,0)%mod;
 
		cout<<ans<<endl;
	}
	
	return 0;
}
 
 
