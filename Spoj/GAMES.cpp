#include <bits/stdc++.h>
using namespace std;

#define N 1000006

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		string S;
		int num = 0, len, pos, dig, temp;
		cin >> S;
		pos = S.size();
		for(int i = 0;i < S.size();i++) {
			if(S[i] == '.') {
				pos = i + 1;
				break;
			}
		}
		len = S.size() - pos;
		if(!len) {
			printf("1\n");
			continue;
		}
		for(int i = pos;i < S.size();i++)
			num = 10 * num + (S[i] - '0');
		dig = pow(10, len);
		for(int i = 1;i <= dig;i++) {
			temp = i * num;
			if(!(temp % dig)) {
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}
		
