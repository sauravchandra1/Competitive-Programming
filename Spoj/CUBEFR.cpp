#include <bits/stdc++.h>
using namespace std;

#define N 1000006

struct data{
	bool ck;
	int diff;
} arr[N];

int main() {
	for(int i = 0;i < N;i++) {
		arr[i].ck = false;
		arr[i].diff = 0;
	}		
	int k, temp = 0;
	for(int i = 2;i <= 100;i++) {
		k = i * i * i;
		for(int j = k;j < N;j += k ) {
			arr[j].ck = true;
			arr[j].diff = 1;
		}
	}
	for(int i = 1;i < N;i++) {
		if(arr[i].ck)
			temp += 1;
		else
			arr[i].diff = temp;
	}
	int t, cnt = 0;
	scanf("%d", &t);
	while(t--) {
		cnt++;
		int n;
		scanf("%d", &n);
		if(!arr[n].ck)
			printf("Case %d: %d\n", cnt, n - arr[n].diff);
		else
			printf("Case %d: Not Cube Free\n", cnt);
	}
	return 0;
} 
		
