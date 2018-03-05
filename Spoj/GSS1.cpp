#include <bits/stdc++.h>
using namespace std;
 
const int siz=5e4+5;
 
struct node{
    int l_sum;
    int r_sum;
    int t_sum;
    int b_sum;
};
 
node tree[4*siz];
int arr[siz];
 
int mx(int a,int b){
    return (a>b? a:b);
}
 
int mx(int a,int b,int c){
    if(a>b)
        return (a>c? a:c);
    else    
        return (b>c? b:c);
}
 
node merg(node left,node right){
    node temp;
    temp.l_sum=mx(left.l_sum,left.t_sum+right.l_sum);
    temp.r_sum=mx(right.r_sum,right.t_sum+left.r_sum);
    temp.t_sum=left.t_sum+right.t_sum;
    temp.b_sum=mx(left.b_sum,right.b_sum,left.r_sum+right.l_sum);
    return temp;
}
 
void build(int low,int high,int pos){
    if(low==high){
        tree[pos].l_sum=arr[low];
        tree[pos].r_sum=arr[low];
        tree[pos].t_sum=arr[low];
        tree[pos].b_sum=arr[low];
        return ;
    }
    int mid=(low+high)/2;
    int left=2*pos+1;
    int right=2*pos+2;
    build(low,mid,left);
    build(mid+1,high,right);
    tree[pos]=merg(tree[left],tree[right]);
    return ;    
}
 
node query(int low,int high,int start,int en,int pos){
    if(low>en||high<start){
        node temp;
        temp.l_sum=-555555;
        temp.r_sum=-555555; 
        temp.t_sum=0;
        temp.b_sum=-555555;
        return temp;
    }
    if(low>=start&&high<=en)
        return tree[pos];
    else{
        int mid=(low+high)/2;
        int left=2*pos+1;
        int right=2*pos+2;
        node a=query(low,mid,start,en,left);
        node b=query(mid+1,high,start,en,right);
        return merg(a,b);
    }
}
 
int main(){
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
        scanf("%d",&arr[i]);
    build(0,num-1,0);
    int q;
    scanf("%d",&q);
    while(q--){
        int start,en;
        scanf("%d %d",&start,&en);  
        node ans=query(0,num-1,start-1,en-1,0);
        printf("%d\n",ans.b_sum);
    }
    return 0;
}
        
