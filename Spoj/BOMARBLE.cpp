#include <bits/stdc++.h>
using namespace std;

int main() {
	while(1) {
		int n;
		scanf("%d", &n);
		if(!n)
			break;
		printf("%d\n", 5 * n + 3 * ((n * (n - 1)) / 2) - n + 1);
	}
	return 0;
}
