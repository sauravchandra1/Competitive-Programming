#include <iostream>
using namespace std;

#define Modulus 998244353
#define N 1100

long long dp[N][2 * N][2][2];
int main() {
	long long totalNumberOfRow = 3, totalNumberOfPartition = 4;
	// There are four states of DP table -> dp[a][b][c][d]
	// First state describes the row a
	// Second state describes the number of partition b
	// Third state describes the color of the box c, placed in first row
	// Fourth state describes the color of the box d, place in second row
	dp[1][1][0][0] = dp[1][1][1][1] = 1;
	dp[1][2][0][1] = dp[1][2][1][0] = 1;

	for (int i = 2; i <= totalNumberOfRow; i++) {
		for (int colorOfBoxInFirstRowLastColumn = 0; colorOfBoxInFirstRowLastColumn < 2; colorOfBoxInFirstRowLastColumn++) {
			for (int colorOfBoxInSecondRowLastColumn = 0; colorOfBoxInSecondRowLastColumn < 2; colorOfBoxInSecondRowLastColumn++) {
				for (int partition = 1; partition <= totalNumberOfPartition; partition++) {

					if (colorOfBoxInFirstRowLastColumn == 0 && colorOfBoxInSecondRowLastColumn == 0) {
						dp[i][partition][0][0] = (dp[i][partition][0][0] + dp[i - 1][partition][0][0] 
							+ dp[i - 1][partition][0][1] + dp[i - 1][partition][1][0]) % Modulus;
						dp[i][partition + 1][0][0] = (dp[i][partition + 1][0][0] + dp[i - 1][partition][1][1]) % Modulus;
					}

					else if (colorOfBoxInFirstRowLastColumn == 0 && colorOfBoxInSecondRowLastColumn == 1) {
						dp[i][partition][0][1] = (dp[i][partition][0][1] + dp[i - 1][partition][0][1]) % Modulus;
						dp[i][partition + 1][0][1] = (dp[i][partition 
							+ 1][0][1] + dp[i - 1][partition][0][0] + dp[i - 1][partition][1][1]) % Modulus;
						dp[i][partition + 2][0][1] = (dp[i][partition + 2][0][1] 
							+ dp[i - 1][partition][1][0]) % Modulus;
					}

					else if (colorOfBoxInFirstRowLastColumn == 1 && colorOfBoxInSecondRowLastColumn == 0) {
						dp[i][partition][1][0] = (dp[i][partition][1][0] + dp[i - 1][partition][1][0]) % Modulus;
						dp[i][partition + 1][1][0] = (dp[i][partition + 1][1][0] 
							+ dp[i - 1][partition][0][0] + dp[i - 1][partition][1][1]) % Modulus;
						dp[i][partition + 2][1][0] = (dp[i][partition + 2][1][0] + dp[i - 1][partition][0][1]) % Modulus;
					}
					
					else if (colorOfBoxInFirstRowLastColumn == 1 && colorOfBoxInSecondRowLastColumn == 1) {
						dp[i][partition][1][1] = (dp[i][partition][1][1] + dp[i - 1][partition][0][0]
						 + dp[i - 1][partition][0][1] + dp[i - 1][partition][1][0]) % Modulus;
						dp[i][partition + 1][1][1] = (dp[i][partition + 1][1][1] + dp[i - 1][partition][0][0]) % Modulus;
					}
				}
			}
		}
	}
	// Add answer of all combinations of colors in last column
	long long answer = (dp[totalNumberOfRow][totalNumberOfPartition][0][0] + dp[totalNumberOfRow][totalNumberOfPartition][1][1] 
	+ dp[totalNumberOfRow][totalNumberOfPartition][0][1] + dp[totalNumberOfRow][totalNumberOfPartition][1][0]) % Modulus;
	cout << answer << endl;
	return 0;
}