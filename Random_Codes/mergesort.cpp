#include<iostream>
using namespace std;

void merge(int *left,int *right,int *A,int nL,int nR){
	int i=0,j=0,k=0;
	while(i<nL&&j<nR){
		if(left[i]<=right[j]){
			A[k]=left[i];
			i++;
		}
		else{
			A[k]=right[j];
			j++;
		}
		k++;
	}
	while(i<nL){
		A[k]=left[i];
		i++;
		k++;
	}
	while(j<nR){
		A[k]=right[j];
		j++;
		k++;
	}
}

void mergesort(int *A,int sizeA){
	if(sizeA<2)
		return ;
	int mid=sizeA/2;
	int *left=new int[mid];
	int *right=new int[sizeA-mid];
	for(int i=0;i<mid;i++)
		left[i]=A[i];
	for(int i=mid;i<sizeA;i++)
		right[i-mid]=A[i];
	mergesort(left,mid);
	mergesort(right,sizeA-mid);
	merge(left,right,A,mid,sizeA-mid);
}

int main(){
	cout<<"Enter The Total Number"<<endl;
	int sizeA;
	cin>>sizeA;
	cout<<"Enter The Numbers"<<endl;
	int *A=new int[sizeA];
	for(int i=0;i<sizeA;i++){
		cin>>A[i];
	}
	mergesort(A,sizeA);
	cout<<"Sorted Numbers :";
	for(int i=0;i<sizeA;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
}