#include <bits/stdc++.h>
using namespace std;

#define N 2505
#define pb push_back

vector< int > A, B, C, D;
vector< int > S1, S2;

int main(){
	int n, a, b, c, d, low, up, ans=0;
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		A.pb(a);
		B.pb(b);
		C.pb(c);
		D.pb(d);
	}
	for(int i = 0;i < n;i++) 
		for(int j = 0; j < n;j++)
			S1.pb(A[i] + B[j]);	
	for(int i = 0;i < n;i++) 
		for(int j = 0; j < n;j++)
			S2.pb(-(C[i] + D[j]));
	sort(S1.begin(), S1.end());
	sort(S2.begin(), S2.end());
	for(int i = 0;i < S1.size();i++) {
		low = lower_bound(S2.begin(), S2.end(), S1[i]) - S2.begin();
		up = upper_bound(S2.begin(), S2.end(), S1[i]) - S2.begin();
		ans += up - low;
	}
	printf("%d\n", ans);
	return 0;
}
