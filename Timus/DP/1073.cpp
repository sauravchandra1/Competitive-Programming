#include <bits/stdc++.h>
using namespace std;

const int siz = 6e4 + 4;

int main() {
	int N, tab[siz];
	scanf("%d", &N);
	tab[0] = 0;
	tab[1] = 1;
	for (int i = 2; i <= N; i++) {
		tab[i] = i;
		for (int j = 1; j <= sqrt(i); j++) 
			tab[i] = min(tab[i], 1 + tab[i - j * j]);
	}
	printf("%d\n", tab[N]);
	return 0;
}
