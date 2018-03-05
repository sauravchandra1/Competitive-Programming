#include <bits/stdc++.h>
using namespace std;

int main(){
	int num;
	scanf("%d",&num);
	int temp=num,temp1,x;
	set<int> con;
	while(temp--){
		scanf("%d",&x);
		con.insert(x);
		scanf("%d",&temp1);
		while(temp1--){
			scanf("%d",&x);
			con.insert(x);
		}
	}
	printf("%lu\n",con.size()-num);
	return 0;
}
