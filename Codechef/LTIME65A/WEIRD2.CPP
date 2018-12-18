#include <bits/stdc++.h>
using namespace std;
#define N 1000006
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		set < int > val;
		vector < int > vec(n);
		map < int, int > cnt;
		for (int i = 0; i < n; i++) { 
			cin >> vec[i];
			cnt[vec[i]]++;
			val.insert(vec[i]);
		}
		set < int > :: iterator it;
		int elem;
		int freq;
		long long ans = 0;
		for (it = val.begin(); it != val.end(); it++) {
			elem = *it;
			freq = cnt[elem];
			for (int j = 1; j <= freq; j++) {
				if (cnt[elem] >= j && cnt[j] >= elem)
					ans++;
			}
		}
		cout << ans << endl;
	}	
	return 0;
}