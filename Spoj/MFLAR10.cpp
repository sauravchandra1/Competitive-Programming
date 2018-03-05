#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	while(1) {
		getline(cin, S);
		if(S[0] == '*')
			break;
		char ch1 = S[0], ch2;
		int flag = 0;
		if(ch1 > 96)
			ch2 = ch1 - 32;
		else 
			ch2 = ch1 + 32;
		for(int i = 1;i < S.size();i++) {
			if(S[i] == ' ') {
				if(!((S[i + 1] == ch1 )||( S[i + 1] == ch2))) {
					printf("N\n");
					flag = 1;
					break;
				}
			}
		}
		if(!flag)
			printf("Y\n");
	}
	return 0;
}
