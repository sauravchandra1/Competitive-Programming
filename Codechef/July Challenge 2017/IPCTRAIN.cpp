#include<iostream>
#include<algorithm>
#include<math.h>
 
using namespace std;
 
long long int reamaining_lactures=0;
 
void constructTree(int input[],int segTree[],int low,int high,int pos){
 
	if(low==high){
		segTree[pos]=input[low];
		return ;
	}
 
	int mid=(low+high)/2;
 
	constructTree(input,segTree,low,mid,2*pos+1);
	constructTree(input,segTree,mid+1,high,2*pos+2);
 
	segTree[pos]=segTree[2*pos+1]+segTree[2*pos+2];
}
 
struct str{
	
   int value;
   int index;
 };
 
 int cmp(const void *a,const void *b){
	 
  struct str *a1=(struct str *)a;
  struct str *a2=(struct str*)b;
  
  if((*a1).value>(*a2).value)
	return -1;
  else if((*a1).value<(*a2).value)
	return 1;
  else return 0;
}
 
void query(int segmentTree[],int startRange,int endRange,int low,int high,int pos){
 
	if(reamaining_lactures==0)
		return ;
 
	if(segmentTree[pos]>=(high-low+1))
		return ;
 
    if(low>high||startRange>high||endRange<low){
        return ;
    }
 
    if(low == high) {
        segmentTree[pos]=1;
        reamaining_lactures--;
        return ;
    }
 
    int middle = (low + high)/2;
 
    query(segmentTree,startRange,endRange,low,middle,2*pos+1);
    query(segmentTree,startRange,endRange,middle+1,high,2*pos+2);
 
    segmentTree[pos]=segmentTree[2*pos+1]+segmentTree[2*pos+2];
}
 
 
int main(){
 
	int test;
	cin>>test;
 
	while(test--){
 
		int trainers,totaldays;
		cin>>trainers>>totaldays;
 
		int *reachday=new int[trainers];
		int *lacture=new int[trainers];
		long long int *sadness=new long long int[trainers];
 
		for(int i=0;i<trainers;i++){
			cin>>reachday[i];
			cin>>lacture[i];
			cin>>sadness[i];
		}
 
		 //Height of segment tree
		int height = (int)(ceil(log2(totaldays))); 
 
		int poweroftwo=pow(2,height);
 
		//Maximum size of segment tree
		int max_size = 2*(int)pow(2, height) - 1; 
 
		int *input=new int[poweroftwo];
		int *segTree=new int[max_size];
 
		for(int i=0;i<totaldays;i++)
			input[i]=0;
 
		for(int i=totaldays;i<poweroftwo;i++)
			input[i]=1;
 
		int low=0,high=poweroftwo-1,pos=0;
 
		constructTree(input,segTree,low,high,pos);
		
		int current_trinner_reachday,current_index;
		long long int total_sadness=0;
		
		str *objects=new str[trainers];
		
		for(int i=0;i<trainers;i++){
			objects[i].value=sadness[i];
			objects[i].index=i;
		}
		
		qsort(objects,trainers,sizeof(objects[0]),cmp);
 
		for(int i=0;i<trainers;i++){
 
			current_index=objects[i].index;
			current_trinner_reachday=reachday[current_index]-1;
			reamaining_lactures=lacture[current_index];
 
			query(segTree,current_trinner_reachday,poweroftwo-1,low,high,pos);
 
			total_sadness=(reamaining_lactures*sadness[current_index])+total_sadness;
		} 
 
		cout<<total_sadness<<endl;
 
	}
	return 0;
}
 
