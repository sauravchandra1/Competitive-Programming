#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
	    long long n, m, k, l;
	    cin >> n >> m >> k >> l;
	    set < long long > bucket;
	    long long tmp;
	    for (int i = 0; i < n; i++)  {
	        cin >> tmp;
	        bucket.insert(tmp);
	    }
	    bucket.insert(k);
	    set < long long > :: iterator it;
	    long long curr_time = m * l, elem, ans = LLONG_MAX;
	    for (it = bucket.begin(); it != bucket.end(); it++) {
	        curr_time += l;
	        elem = *it;
	        if (elem > k)
	            break;
	        if (curr_time < elem) {
	        	ans = 0;
	        	break;
	        }
	       ans = min(ans, curr_time - elem);
	    }
	    cout << ans << endl;
	}
	return 0;
}

