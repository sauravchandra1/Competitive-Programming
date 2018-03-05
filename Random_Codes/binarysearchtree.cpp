#include<iostream>
using namespace std;
struct node{
	int data;
	node* left;
	node* right;
};
node* root=NULL;
node* getnewnode(){
	node* currentnode=new node;
	currentnode->left=NULL;
	currentnode->right=NULL;
	return currentnode;
}
void insert(int data){
	if(root==NULL){
		root=getnewnode();
		root->data=data;
	}
	else{
		node* currentnode=root;
		node* prev=NULL;
		int x=0;
		while(currentnode!=NULL){
			if(currentnode->data>=data){
				prev=currentnode;
				currentnode=currentnode->left;
				x=0;
			}
			else{
				prev=currentnode;
				currentnode=currentnode->right;
				x=1;
			}
		}
		if(x==1){
			currentnode=getnewnode();
			currentnode->data=data;
			prev->right=currentnode;
		}
		else if(x==0){
			currentnode=getnewnode();
			currentnode->data=data;
			prev->left=currentnode;
		}
	}
}
bool search(int data){
	node* currentnode=root;
	bool check;
	if(currentnode==NULL)
		return false;
	else{
		while(1){
			if(currentnode==NULL){
				check=false;
				break;
			}
			else if(currentnode->data==data){
				check=true;
				break;
			}
			
			else if(currentnode->data>=data)
				currentnode=currentnode->left;
			else
				currentnode=currentnode->right;
		}
	}
	return check;
}
int main(){
	int test; 
	cout<<"Enter Test Case: "<<endl;
	cin>>test;
	while(test--){
		cout<<"Enter Number: "<<endl;
		int x;
		cin>>x;
		insert(x);
	}
	cout<<"Enter The Number of Queries: "<<endl;
	int t;
	cin>>t;
	while(t--){
		int x;
		cout<<"Enter The Number to Search: "<<endl;
		cin>>x;
		bool check=search(x);
		if(check==true)
			cout<<"The Number is Found in Tree: "<<endl;
		else
			cout<<"The Number is Not Found in Tree: "<<endl;
	}
	return 0;
}