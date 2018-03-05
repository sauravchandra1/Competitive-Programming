#include<iostream>
using namespace std;
struct data{
	int fee,fun;	
};
int main(){
	while(1){
		int budget,party;
		cin>>budget>>party;
		if(budget==0&&party==0)
			break;
		int table[party+1][budget+1];
		for(int i=0;i<party+1;i++){
			table[i][0]=0;
		}
		for(int i=0;i<budget+1;i++){
			table[0][i]=0;
		}
		data arr[party+1];
		for(int i=1;i<party+1;i++){
			cin>>arr[i].fee>>arr[i].fun;
		}
		for(int i=1;i<party+1;i++){
			for(int j=1;j<budget+1;j++){
				if(j<arr[i].fee){
					table[i][j]=table[i-1][j];
				}
				else{
					table[i][j]=max(arr[i].fun+table[i-1][j-arr[i].fee],table[i-1][j]);
				}
			}
		}
		int fees=table[party][budget],funs=0;
		for(int i=0;i<budget+1;i++){
			if(table[party][i]==fees){
				funs=i;
				break;
			}
		}
		cout<<funs<<" "<<fees<<endl;
	}
	return 0;
}