#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define N 55
#define MOD 1000000007
int n, s;
long long dp[N][N];
long long gcdAns[N][N];
long long numberCount[N][N][N];
vector<int> vec;
void pre() {
	for (int balls = 0; balls < N; balls++) {
		dp[1][balls] = 1;
		numberCount[1][balls][balls] = 1;
	}
	for (int box = 2; box < N; box++) {
		for (int balls = box; balls < N; balls++) {
			for (int lastBoxNumber = 1; lastBoxNumber <= (balls - (box - 1)); lastBoxNumber++) {
				dp[box][balls] = (dp[box][balls] + dp[box - 1][balls - lastBoxNumber]) % MOD;
				gcdAns[box][balls] = (gcdAns[box][balls] + gcdAns[box - 1][balls - lastBoxNumber]) % MOD;
				for (int numberCountSoFar = 1; numberCountSoFar < N; numberCountSoFar++) {
					gcdAns[box][balls] = (gcdAns[box][balls] + (__gcd(numberCountSoFar, lastBoxNumber) 
					* numberCount[box - 1][balls - lastBoxNumber][numberCountSoFar]) % MOD) % MOD;
				}
				for (int countSoFar = 1; countSoFar < N; countSoFar++) {
					numberCount[box][balls][countSoFar] += numberCount[box - 1][balls - lastBoxNumber][countSoFar]; 
				}
				numberCount[box][balls][lastBoxNumber] += dp[box - 1][balls - lastBoxNumber];			
			}
		}
	}
}
int main() {
	pre();
	int t;
	cin >> t;
	while (t--) {
		vec.clear();
		cin >> n >> s;
		int inputVariable, negativeCount = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> inputVariable;
			if (inputVariable < 0)
				negativeCount++;
			else { 
				sum += inputVariable;
				vec.push_back(inputVariable);
			}
		}
		if (sum > s || (s - sum) < negativeCount || n == 1 || (negativeCount == 0 && (s != sum))) {
			cout << "0" << endl;
			continue;
		}
		int vecSize;
		long long ans = 0;
		if (negativeCount == 1) {
			vec.push_back(s - sum);
			vecSize = vec.size();
			for (int i = 0; i < vecSize; i++) {
				for (int j = i + 1; j < vecSize; j++) {
					ans = (ans + __gcd(vec[i], vec[j])) % MOD;
				}
			}
			cout << ans << endl;
			continue;
		}
		vecSize = vec.size();
		for (int i = 0; i < vecSize; i++) {
			for (int j = i + 1; j < vecSize; j++) {
				ans = (ans + __gcd(vec[i], vec[j])) % MOD;
			}
		}
		if (negativeCount == 0) {
			cout << ans << endl;
			continue;
		}
		ans = (ans * dp[negativeCount][s - sum]) % MOD;
		ans = (ans + gcdAns[negativeCount][s - sum]) % MOD;
		for (int i = 0; i < vecSize; i++) {
			for (int j = 1; j < N; j++) {
				ans = (ans + __gcd(vec[i], j) * numberCount[negativeCount][s - sum][j]) % MOD;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

