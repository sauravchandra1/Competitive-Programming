#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	set<int> adj[n + 1];
	int x, y;
	for (int i = 1; i <= n - 1; i++) {
		cin >> x >> y;
		adj[x].insert(y);
		adj[y].insert(x);
	}
	set<int> :: iterator it;
	// for (int i = 1; i <= n; i++) {
	// 	cout << i << " --> ";
	// 	for (it = adj[i].begin(); it != adj[i].end(); it++)
	// 		cout << *it << " ";
	// 	cout << endl;
	// }
	vector< pair<int, int> > removeNodes;
	int elem;
	int flag = 0;
	int check = 4;
	while (k--) {
		if (k == 0)
			check = 3;
		int isSizeOneFound = 0;
		for (int i = 1; i <= n; i++) {
			if (adj[i].size() == 1) {
				isSizeOneFound = 1;
				for (it = adj[i].begin(); it != adj[i].end(); it++) {
					elem = *it;
					if ((int)adj[elem].size() < check) {
						flag = 1;
						break;
					}
					removeNodes.push_back(make_pair(i, elem));
				}
			}
		}
		if (isSizeOneFound == 0)
			flag = 1;
		if (flag)
			break;
		for (int i = 0; i < (int)removeNodes.size(); i++) {
			adj[removeNodes[i].first].erase(removeNodes[i].second);
			adj[removeNodes[i].second].erase(removeNodes[i].first);
		}
		if (k) {
			for (int i = 0; i < (int)removeNodes.size(); i++) {
				if (adj[removeNodes[i].second].size() != 1) {
					flag = 1;
					break;
				}
			}
		}
		removeNodes.clear();
	}
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() != 0) {
			flag = 1;
			break;
		}
	}
	flag ? cout << "No" : cout << "Yes";
	return 0;
}
