#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll mod = 1e9 + 7;
 
#define pb push_back
#define mp make_pair
 
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, k;
		scanf("%d %d", &n, &k);
		int arr[103];
		for(int i = 0;i < n;i++)
			scanf("%d", &arr[i]);
		sort(arr, arr + n);
		printf("%d\n", arr[(n + k - 1)/2]);
	}
	return 0;
}
 
