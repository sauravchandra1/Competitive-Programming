#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int siz=1e7+5;

int nume[siz];
int deno[siz];

int main(){
	int up=1,down=1;
		nume[1]=1,deno[1]=1;
		int count=2;
		while(1){
			if(count>=siz-1)
				break;
			else if(up==1){
				down++;
				while(1){
					nume[count]=up;
					deno[count]=down;
					count++;
					if(count>=siz-1)
						break;
					if(down==1)
						break;
					up++;
					down--;
				}
			}
			else if(down==1){
				up++;	
				while(1){
					nume[count]=up;
					deno[count]=down;
					count++;
					if(count>=siz-1)
						break;
					if(up==1)
						break;
					up--;
					down++;
				}
			}

		}
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		printf("TERM %d IS %d/%d\n",n,nume[n],deno[n]);
	}
	return 0;
}
		
