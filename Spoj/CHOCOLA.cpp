#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define N 1003

int sum1[N], sum2[N];
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		sum1[0] = sum2[0] = 0;
		vector< int > A, B;
		A.pb(0), B.pb(0);
		int m, n, temp; 
		scanf("%d %d", &m, &n);
		m--, n--;
		int i = m, j = n, ans = 0;
		for(int i = 0;i < m;i++) {
			scanf("%d", &temp);
			A.pb(temp);
		}
		for(int i = 0;i < n;i++) {
			scanf("%d", &temp);
			B.pb(temp);
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		for(int i = 1;i <= m;i++)
			sum1[i] = A[i] + sum1[i - 1];
		for(int i = 1;i <= n;i++)
			sum2[i] = B[i] + sum2[i - 1];
		while(i > 0 && j > 0) {
			if(A[i] >= B[j]) {
				ans += sum2[j] + A[i];
				i--;
			}
			else {
				ans += sum1[i] + B[j];
				j--;
			}
		}
		if(i > 0) 
			ans += sum1[i];
		if(j > 0)
			ans += sum2[j];
		printf("%d\n", ans);
	}
	return 0;
}
