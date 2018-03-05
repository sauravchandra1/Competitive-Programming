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
			currentnode=new node;
			currentnode->data=data;
			prev->right=currentnode;
		}
		else if(x==0){
			currentnode=new node;
			currentnode->data=data;
			prev->left=currentnode;
		}
	}
}
int findheight(node* root){
	int height=0;
	if(root==NULL)
		return -1;
	else
		height=max(findheight(root->left),findheight(root->right))+1;
	return height;
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
	cout<<"The Height of The Tree Is :"<<endl;
	int height=findheight(root);
	cout<<height<<endl;
	return 0;
}
