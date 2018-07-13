#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const ll mod = 1e9 + 7;
const int siz = 1e5 + 5;

#define eb emplace_back
#define mp make_pair
#define OPEN 0

int main() {
	if (OPEN) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	int arr[21][21];
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 20; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int mx = 0, sum = 0;
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 20; j++) {
			//up-down-left-right
			if (i + 3 <= 20) {
				sum = arr[i][j] * arr[i + 1][j] * arr[i + 2][j] * arr[i + 3][j];
				mx = max(mx, sum);
			}
			if (i - 3 >= 1) {
				sum = arr[i][j] * arr[i - 1][j] * arr[i - 2][j] * arr[i - 3][j];
				mx = max(mx, sum);
			}
			if (j + 3 <= 20) {
				sum = arr[i][j] * arr[i][j + 1] * arr[i][j + 2] * arr[i][j + 3];
				mx = max(mx, sum);
			}
			if (j - 3 >= 1) {
				sum = arr[i][j] * arr[i][j - 1] * arr[i][j - 2] * arr[i][j - 3];
				mx = max(mx, sum);
			}
			//diagonal
			if (i - 3 >= 1 && j + 3 <= 20) {
				sum = arr[i][j] * arr[i - 1][j + 1] * arr[i - 2][j + 2] * arr[i - 3][j + 3];
				mx = max(mx, sum);
			}
			if (i - 3 >= 1 && j - 3 >= 1) {
				sum = arr[i][j] * arr[i - 1][j - 1] * arr[i - 2][j - 2] * arr[i - 3][j - 3];
				mx = max(mx, sum);
			}
			if (i + 3 <= 20 && j - 3 >= 1) {
				sum = arr[i][j] * arr[i + 1][j - 1] * arr[i + 2][j - 2] * arr[i + 3][j - 3];
				mx = max(mx, sum);
			}
			if (i + 3 <= 20 && j + 3 <= 20) {
				sum = arr[i][j] * arr[i + 1][j + 1] * arr[i + 2][j + 2] * arr[i + 3][j + 3];
				mx = max(mx, sum);
			}
		}
	}
	cout << mx << endl;
	
	return 0;
}
