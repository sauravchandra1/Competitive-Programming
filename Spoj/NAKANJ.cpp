#include <bits/stdc++.h>
using namespace std;

int vis[100][100];
int s, e;

struct data {
	int x, y, val;
};

int move(int x, int y) {
	int val = 0;
	queue< data > Q;
	data P;
	P.x = x;
	P.y = y;
	P.val = 0;
	Q.push(P);
	vis[x][y] = 1;
	while(!Q.empty()) {
		P = Q.front();
		Q.pop();
		x = P.x;
		y = P.y;
		val = P.val;
		if(x > 8 || x < 1 || y > 8 || y < 1)
			continue;
		if(x == s && y == e) 
			return val;
		if(vis[x + 2][y + 1] == 0) {
			P.x = x + 2;
			P.y = y + 1;
			P.val = val + 1;
			Q.push(P);
			vis[x + 2][y + 1] = 1;
		}
		if(vis[x + 1][y + 2] == 0) {
			P.x = x + 1;
			P.y = y + 2;
			P.val = val + 1;
			Q.push(P);
			vis[x + 1][y + 2] = 1;
		}
		if(vis[x - 1][y + 2] == 0) {
			P.x = x - 1;
			P.y = y + 2;
			P.val = val + 1;
			Q.push(P);
			vis[x - 1][y + 2] = 1;
		}
		if(vis[x + 2][y - 1] == 0) {
			P.x = x + 2;
			P.y = y - 1;
			P.val = val + 1;
			Q.push(P);
			vis[x + 2][y - 1] = 1;
		}
		if(vis[x - 2][y + 1] == 0) {
			P.x = x - 2;
			P.y = y + 1;
			P.val = val + 1;
			Q.push(P);
			vis[x - 2][y + 1] = 1;
		}
		if(vis[x + 1][y - 2] == 0) {
			P.x = x + 1;
			P.y = y - 2;
			P.val = val + 1;
			Q.push(P);
			vis[x + 1][y - 2] = 1;
		}
		if(vis[x - 1][y - 2] == 0) {
			P.x = x - 1;
			P.y = y - 2;
			P.val = val + 1;
			Q.push(P);
			vis[x - 1][y - 2] = 1;
		}
		if(vis[x - 2][y - 1] == 0) {
			P.x = x - 2;
			P.y = y - 1;
			P.val = val + 1;
			Q.push(P);
			vis[x - 2][y - 1] = 1;
		}
	}
}
	
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		memset(vis, 0, sizeof vis);
		int x, y;
		string S, E;
		cin >> S;
		cin >> E;
		x = (S[0] - 96);
		y = (S[1] - '0');
		s = (E[0] - 96);
		e = (E[1] - '0');
		int ans = move(x, y);
		printf("%d\n", ans);
	}
	return 0;
}
