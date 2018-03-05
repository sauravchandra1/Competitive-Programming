#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, ans = 0, p = 0, temp;
		scanf("%d", &n);
		ans = n;
		if(!(n & 1)){
			ans = 0;
			temp = n;
			while(temp != 0) {
				p++;
				temp = temp >> 1;
			}
			p--;
			while(n != 0) {
				if(n & 1)
					temp = 1;
				else 
					temp = 0;
				n = n >> 1;
				ans += temp * pow(2, p);
				p--;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
