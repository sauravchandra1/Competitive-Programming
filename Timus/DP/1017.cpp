#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int siz = 505;

ll tab[siz][siz], ans;

int main() {
	tab[3][2] = tab[4][2] = 1;
	int N;
	scanf("%d", &N);	
	for (int i = 5; i <= N; i++) {
		for (int j = 2; j <= i; j++) {
		    if(j == 2)
		        tab[i][j] = tab[i - j][j] + 1;
		    else 
			    tab[i][j] = tab[i - j][j] + tab[i - j][j - 1];
		}
	}
	for (int i = 1; i <= N; i++)
		ans += tab[N][i];
	printf("%lld\n", ans);
	return 0;
}
