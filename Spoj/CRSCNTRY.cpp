#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define N 2005

vector< int > V1, V2;
int dp[N][N];

int max(int a, int b) {
	return (a > b ? a : b);
}

int lcs(int len1, int len2) {
	if(len1 < 0 || len2 < 0)
		return 0;
	if(dp[len1][len2] != -1)
		return dp[len1][len2];
	if(V1[len1] == V2[len2]) {
		dp[len1][len2] = lcs(len1 - 1 ,len2 - 1) + 1;
		return dp[len1][len2];
	}
	else {
		dp[len1][len2] = max(lcs(len1, len2 - 1), lcs(len1 - 1, len2));
		return dp[len1][len2];
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		V1.clear();
		int ans = 0, mx = 0, temp;
		char ch;
		do {
			scanf("%d%c", &temp, &ch);
			V1.pb(temp);
		} while(ch != '\n');
		while(1) {
			V2.clear();
			do {
				scanf("%d%c", &temp, &ch);
				V2.pb(temp);
			} while(ch != '\n');
			if(V2[0] == 0)
				break;
			memset(dp, -1, sizeof dp);
			/*for(int i = 0;i < V1.size();i++)
				printf("%d ", V1[i]);
			printf("\n");
			for(int i = 0;i < V2.size();i++)
				printf("%d ", V2[i]);
			printf("\n");*/			
			ans = lcs(V1.size() - 2, V2.size() - 2);
			//printf("%d\n", ans);
			if(ans > mx)
				mx = ans;
		}
		printf("%d\n", mx);		
	}
	return 0;
}
