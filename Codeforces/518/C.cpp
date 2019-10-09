#include <bits/stdc++.h>
using namespace std;
#define N 110
int main() {
	int n, m; 
	cin >> n >> m;
	vector < pair < int, int > > tree[N];
	int x, y;
	for (int i = 1; i <= n; i++)
		tree[i].push_back(make_pair(i, i));
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		tree[x].push_back(make_pair(x, n + i));
		tree[y].push_back(make_pair(y, n + i));
	}
	for (int i = 0; i < N; i++) {
		if (tree[i].size() > 0) {
			cout << tree[i].size() << endl;
			for (int j = 0; j < (int)tree[i].size(); j++) {
				cout << tree[i][j].first << " " << tree[i][j].second << endl;
			}
		}
	}
	return 0;
}