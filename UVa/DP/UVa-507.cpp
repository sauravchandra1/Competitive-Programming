#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const int mod = 1e9 + 7;
const int siz = 1e5 + 5;

#define eb emplace_back
#define mp make_pair
#define OPEN 0

class cmp {
public:
	bool operator()(pair < int, pii > n1, pair < int, pii > n2) {
		if (n1.first == n2.first) {
			if (n1.second.second - n1.second.first == n2.second.second - n2.second.first) {
				return n1.second.first > n2.second.first;
			}
			else if (n1.second.second - n1.second.first < n2.second.second - n2.second.first) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
        	return (n1.first < n2.first);
        }
    }
};

int main() {
	if (OPEN) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	int test;
	scanf("%d", &test);
	int cnt = test;
	while (test--) {
		priority_queue < pair < int, pii >, vector < pair < int, pii > >, cmp > pq;
		int N, x;
		pii p;
		pair < int, pii > res;
		scanf("%d", &N);
		vector < int > vec;
		for (int i = 0; i < N - 1; i++) {
			scanf("%d", &x);
			vec.eb(x);		
		}
		int mx = 0, start = 1, end = 1, sum = 0, s, e;
		for (int i = 0; i < int(vec.size()); i++) {
			sum += vec[i];
			end++;
			if (sum < 0) {
				sum = 0;
				start = end = i + 2;
			}
			else if (sum >= mx) {
				mx = sum;
				s = start;
				e = end;
				p.first = s;
				p.second = e;
				pq.push({mx, p});
			}
		}
		if (mx == 0) {
			printf("Route %d has no nice parts\n", cnt - test);
		}
		else {
			res = pq.top();
			printf("The nicest part of route %d is between stops %d and %d\n", cnt - test, res.second.first, res.second.second);
		}
	}
	return 0;
}
