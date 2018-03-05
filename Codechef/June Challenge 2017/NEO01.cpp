#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--) {
		int n;
		cin>>n;
		long long int sum=0;
		int x,j=0,count=0,neg[100001]={0};
		for(int i=0;i<n;i++){
			cin>>x;
			if(x>=0){
				sum=sum+x;
				count++;
			}
			else{
				neg[j]=x;
				j++;
			}
		}
	    sort(neg,neg+j);
	    int ind=0,temp=0;
	    for(int i=j-1;i>=0;i--){
	    	temp=1;
	    	if(ind==0){
	    		if(((sum+neg[i])*(count+1))>=(sum*count+neg[i])){
	    			sum=sum+neg[i];
	    			count++;
	    		}
	    		else{
	    			sum=sum*count+neg[i];
	    			ind=1;
	    		}
	    	}
	    	else if(ind==1){
	    		sum=sum+neg[i];
	    	}
	    }
	    if(temp==0)
	    	sum=sum*count;
	    cout<<sum<<endl;
	}
	return 0;
} 
 
