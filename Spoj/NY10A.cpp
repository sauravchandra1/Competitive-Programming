#include <bits/stdc++.h>
using namespace std;

int main(){
	int test;
	scanf("%d",&test);
	int count=0;
	while(test--){
		int num;
		scanf("%d",&num);
		int arr[8];
		memset(arr,0,sizeof arr);
		count++;
		string sq;
		cin>>sq;
		int len=sq.size()-2;
		for(int i=0;i<len;i++){
			if((sq[i]=='T')&&(sq[i+1]=='T')&&(sq[i+2]=='T'))
				arr[0]++;
			else if((sq[i]=='T')&&(sq[i+1]=='T')&&(sq[i+2]=='H'))
				arr[1]++;
			else if((sq[i]=='T')&&(sq[i+1]=='H')&&(sq[i+2]=='T'))
				arr[2]++;
			else if((sq[i]=='T')&&(sq[i+1]=='H')&&(sq[i+2]=='H'))
				arr[3]++;
			else if((sq[i]=='H')&&(sq[i+1]=='T')&&(sq[i+2]=='T'))
				arr[4]++;
			else if((sq[i]=='H')&&(sq[i+1]=='T')&&(sq[i+2]=='H'))
				arr[5]++;
			else if((sq[i]=='H')&&(sq[i+1]=='H')&&(sq[i+2]=='T'))
				arr[6]++;
			else if((sq[i]=='H')&&(sq[i+1]=='H')&&(sq[i+2]=='H'))
				arr[7]++;
		}
		printf("%d ",count);
		for(int i=0;i<8;i++)
			printf("%d ",arr[i]);
		printf("\n");
	}
	return 0;
}
	
