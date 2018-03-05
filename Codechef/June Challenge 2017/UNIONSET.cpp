#include<iostream>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--){
		int row,col;
		cin>>row>>col;
		int *check=new int[col];
		int **matrix=new int*[row];
		for(int i=0;i<row;i++){
			matrix[i]=new int[col];
		}
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				matrix[i][j]=0;
			}
		}
		int x,n;
		for(int i=0;i<row;i++){
			cin>>x;
			for(int j=0;j<x;j++){
				cin>>n;
				matrix[i][n-1]=1;
			}
		}
		int k=0,ans=0;
		for(int i=0;i<row-1;i++){
			k=0;
			for(int j=0;j<col;j++){
				if(matrix[i][j]==0){
					check[k]=j;
					k++;
				}
			}
			for(int s=i+1;s<row;s++){
				x=1;
				for(int q=0;q<k;q++){
					if(matrix[s][check[q]]!=1){
						x=0;
						break;
					}
				}
				if(x==1)
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
