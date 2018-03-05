#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll arr[11];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int s, n;
		scanf("%d %d", &s, &n);
		arr[0] = 0;
		for(int i = 1;i <= 10;i++)
			arr[i] = 1;
		for(int i = 1;i <=n;i++)
			for(int j = 1;j <= 10;j++)
				arr[j] = arr[j] + arr[j - 1];
		printf("%d %lld\n", s, arr[10]);
	}
	return 0;
}
		
