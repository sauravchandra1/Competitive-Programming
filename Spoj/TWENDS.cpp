#include <bits/stdc++.h>
using namespace std;

#define N 1004

int arr[N];
int dp[N][N];

int max(int a, int b) {
	return (a > b ? a : b);
}

int find(int i, int j) {
	int a, b;
	if(i > j || j < i)
		return 0;
	else if(dp[i][j] != - 1)
		return dp[i][j];
	else {
		if(arr[i + 1] >= arr[j]) 
			a = find(i + 2, j) + arr[i];
		else
			a = find(i + 1, j - 1) + arr[i];
		
		if(arr[i] >= arr[j - 1])
			b = find(i + 1, j - 1) + arr[j];
		else
			b = find(i, j - 2) + arr[j];
		dp[i][j] = max(a, b);
		return dp[i][j];
	}
}
	
int main() {
	int cnt = 0;
	while(1) {
		cnt++;
		memset(dp, - 1, sizeof dp);
		int n, ans = 0, sum = 0;
		scanf("%d", &n);
		if(!n)
			break;
		for(int i = 0;i < n;i++) {
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		ans = find(0, n - 1);
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n", cnt, 2 * ans - sum);
	}
	return 0;
}
	
		
