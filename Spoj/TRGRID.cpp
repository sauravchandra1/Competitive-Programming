#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int l, r;
		scanf("%d %d", &l, &r);
		if(l <= r) {	
			if(l & 1) 
				printf("R\n");
			else 	
				printf("L\n");
		}
		else {
			if(r & 1) 
				printf("D\n");
			else
				printf("U\n");
		}
	}
	return 0;
}
