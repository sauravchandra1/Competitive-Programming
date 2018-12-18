#include <bits/stdc++.h>
using namespace std;
#define N 5003
int visit[N];
map < pair < int, int >, int > ansk, ansl;
vector < int > tree[N], K(N), L(N);
int flag;
int dfs1(int source, int tim, int final) {
	if (flag)
		return tim;
	visit[source] = 1;
	pair < int, int > p;
	p.first = source;
	p.second = tim;
	ansk[p] = 1;
	if (source == final) {
		flag = 1;
		return tim;
	}
	int time;
	for (int i = 0; i < (int)tree[source].size(); i++) {
		if (flag)
			return time;
		int elem = tree[source][i];
		if (visit[elem] == 0) 
			time = dfs1(elem, tim + 1, final);
	}
	return time;
}
int dfs2(int source, int tim, int final) {
	if (flag)
		return tim;
	visit[source] = 1;
	pair < int, int > p;
	p.first = source;
	p.second = tim;
	ansl[p] = 1;
	if (source == final) {
		flag = 1;
		return tim;
	}
	int time;
	for (int i = 0; i < (int)tree[source].size(); i++) {
		if (flag)
			return tim;
		int elem = tree[source][i];
		if (visit[elem] == 0)
			time = dfs2(elem, tim + 1, final);
	}
	return time;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		ansk.clear();
		ansl.clear();
		int n, k, l;
		cin >> n >> k >> l;
		for (int i = 0; i < N; i++)
			visit[i] = 0;
		int x, y;
		for (int i = 0; i < n - 1; i++) {
			cin >> x >> y;
			tree[x].push_back(y);
			tree[y].push_back(x);
		}
		for (int i = 0; i < k; i++)
			cin >> K[i];
		for (int i = 0; i < l; i++)
			cin >> L[i];
		for (int j = 0; j < N; j++)
				visit[j] = 0;
		pair < int, int > p;
		p.first = 1;
		p.second = 0;
		ansk[p] = 1;
		ansl[p] = 1;
		flag = 0;
		int tim = dfs1(K[0], 0, K[1]);
		for (int i = 1; i < k - 1; i++) {
			for (int j = 0; j < N; j++)
				visit[j] = 0;
			flag = 0;
			tim = dfs1(K[i], tim, K[i + 1]);
		}
		for (int j = 0; j < N; j++)
				visit[j] = 0;
		flag = 0;
		tim = dfs2(L[0], 0, L[1]);
		for (int i = 1; i < l - 1; i++) {
			for (int j = 0; j < N; j++)
				visit[j] = 0;
			flag = 0;
			tim = dfs1(L[i], tim, L[i + 1]);
		}
		map < pair < int, int >, int > :: iterator it;
		int ans = 0;
		for (it = ansk.begin(); it != ansk.end(); it++) {
			p = it->first;
			//cout << p.first << " " << p.second << endl;
			if (ansl[p] == 1) {
				ans++;
			}
		}
		for (it = ansl.begin(); it != ansl.end(); it++) {
			p = it->first;
			//cout << p.first << " " << p.second << endl;
		}
		cout << ans << endl;
	}
	return 0;
}