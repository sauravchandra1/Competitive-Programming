#include <bits/stdc++.h>
using namespace std;

stack<int> street;
stack<int> road;
stack<int> order;

int main(){
	while(1){
		int n,flag=0;
		scanf("%d",&n);
		if(n==0)
			break;
		int* arr=new int[n];
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		for(int i=n-1;i>=0;i--)
			order.push(arr[i]);
		int val=1,temp=0,temp1=0;
		while(!order.empty()){
			temp=order.top();
			order.pop();
			if(temp==val){
				road.push(temp);
				val++;
				continue;
			}
			if(!street.empty()){
				temp1=street.top();
				while(temp1==val){
					road.push(temp1);
					street.pop();
					if(!street.empty())
						temp1=street.top();
					val++;
				}
				street.push(temp);
				continue;
			}
			street.push(temp);  
		}
		while(!street.empty()){
			temp=street.top();
			street.pop();
			road.push(temp);
		}
		for(int i=n;i>=1;i--){
			temp=road.top();
			road.pop();
			if(temp!=i){
				printf("no\n");
				flag=1;
				break;
			}
		}
		if(flag==0)
			printf("yes\n");
	}
	return 0;
}
