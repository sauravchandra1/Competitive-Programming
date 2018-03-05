#include <bits/stdc++.h>
using namespace std;
 
#define N 1003
#define pb push_back
#define mp make_pair
#define pii pair< int ,int > 
 
int dp[N][N], row, col, frow, fcol, ans = -1;
vector< string > V;
string S;
 
int max(int a, int b, int c, int d) {
	int mx = -1;
	if(a > mx)
		mx = a;
	if(b > mx)
		mx = b;
	if(c > mx)
		mx = c;
	if(d > mx)
		mx = d;
	return mx;
}
 
int max(int a, int b, int c) {
	int mx = -1;
	if(a > mx)
		mx = a;
	if(b > mx)
		mx = b;
	if(c > mx)
		mx = c;
	return mx;
}
	
int find_path(int i, int j, int val, int pos) {
	if(i < 0 || i > row - 1 || j < 0 || j > col - 1)
		return 0;
	if(V[i][j] != '.')
		return 0;
	if(val == ans-1){
			frow = i;
			fcol = j;
	}
	if(dp[i][j] != -1)
		return dp[i][j];
	else {
		if(pos == 0) {
			dp[i][j] = max(find_path(i, j - 1, val + 1, 2), 
					find_path(i, j + 1, val + 1, 3), 
					find_path(i - 1, j, val + 1, 1), 
					find_path(i + 1, j, val + 1, 4))
					+ 1;
		}
		else if(pos == 1) {
			dp[i][j] = max(find_path(i, j - 1, val + 1, 2), 
					find_path(i, j + 1, val + 1, 3), 
					find_path(i - 1, j, val + 1, 1))
					+ 1;
		}
		else if(pos == 2) {
			dp[i][j] = max(find_path(i, j - 1, val + 1, 2), 
					find_path(i - 1, j, val + 1, 1), 
					find_path(i + 1, j, val + 1, 4))
					+ 1;
		}
		else if(pos == 3) {
			dp[i][j] = max(find_path(i, j + 1, val + 1, 3), 
					find_path(i - 1, j, val + 1, 1), 
					find_path(i + 1, j, val + 1, 4))
					+ 1;
		}
		else if(pos == 4) {
			dp[i][j] = max(find_path(i, j - 1, val + 1, 2), 
					find_path(i, j + 1, val + 1, 3), 
					find_path(i + 1, j, val + 1, 4))
					+ 1;
		}
		return dp[i][j];
	}
}
 
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		V.clear();
		memset(dp, -1, sizeof dp);
		int m, n, mx = 0, flag = 0;
		scanf("%d %d", &col, &row);
		for(int i = 0;i < row;i++) {
			cin>>S;
			V.pb(S);
		}
		for(int i = 0;i < row;i++){
			for( int j = 0;j < col;j++){
				if(V[i][j] == '.'){
					m = i;
					n = j;
					flag = 1;
					break;
				}
			}
			if(flag == 1)
				break;
		}		
		if(m >= row || n >= col){
			printf("Maximum rope length is 0.\n");
			continue;
		}	
		ans = find_path(m, n, 0, 0);
		memset(dp, -1, sizeof dp);
		ans = find_path(m, n, 0, 0);
		ans = -1;
		memset(dp, -1, sizeof dp);
		ans = find_path(frow, fcol, 0, 0);
		if(ans > mx)
			mx = ans;
		printf("Maximum rope length is %d.\n", mx-1);	
	}
	return 0;
}
