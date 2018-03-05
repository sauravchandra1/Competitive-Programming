#include<iostream>
using namespace std;
struct node{
	int data;
	node * link;
};
node * head=NULL;
void createnode(int data,int n){
	node *temp=new node;
	node *current=head;
	temp->data=data;
	if(n==1){
		temp->link=head;
		head=temp;
	}
	else{
		n-=2;
		while(n--){
			current=current->link;
		}
		temp->link=current->link;
		current->link=temp;
	}
}
void print(){
	node *temp=head;
	while(temp!=NULL){
		cout<<"The list is :"<<temp->data<<endl;
		temp=temp->link;
	}
}
void deletenode(int n){
	node *prev=head,*current=head->link;
	if(n==1){
		head=head->link;
	}
	else{
		n-=2;
		for(int i=0;i<n;i++){
			prev=prev->link;
			current=current->link;
		}	
		prev->link=current->link;
	}
}
int main(){
	int test;
	cout<<"Enter number of test"<<endl; 
	cin>>test;
	while(test--){
		cout<<"Enter number and its position :"<<endl;
		int x,n;
		cin>>x>>n;
		createnode(x,n);
		print();
	}
	cout<<"Enter number of positions you want to delete"<<endl;
	int t;
	cin>>t;
	while(t--){
		int n;
		cout<<"Enter the positions you want to delete"<<endl;
		cin>>n;
		deletenode(n);
		print();
	}
	return 0;
}