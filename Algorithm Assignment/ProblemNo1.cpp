#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N 55
#define Modulus 1000000007

long long dp[N][N]; // DP table that contains total number of ways to arrage N balls in N boxes
long long gcdAnswer[N][N]; // GCD answer for N balls arranged in N boxes
long long numberCount[N][N][N]; // Total counting of a number comes in arrangement of N balls in N boxes 

void preCalculation() {

	for (int balls = 0; balls < N; balls++) {
		dp[1][balls] = 1;
		numberCount[1][balls][balls] = 1;
	}

	for (int box = 2; box < N; box++) {
		for (int balls = box; balls < N; balls++) {
			for (int lastBoxNumber = 1; lastBoxNumber <= (balls - (box - 1)); lastBoxNumber++) {

				dp[box][balls] = (dp[box][balls] + dp[box - 1][balls - lastBoxNumber]) % Modulus;
				gcdAnswer[box][balls] = (gcdAnswer[box][balls] + gcdAnswer[box - 1][balls - lastBoxNumber]) % Modulus;

				for (int numberCountSoFar = 1; numberCountSoFar < N; numberCountSoFar++) {
					gcdAnswer[box][balls] = (gcdAnswer[box][balls] + (__gcd(numberCountSoFar, lastBoxNumber) 
					* numberCount[box - 1][balls - lastBoxNumber][numberCountSoFar]) % Modulus) % Modulus;
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
	preCalculation(); // Calculation of total count of different numbers in last box

	int givenArrayLength = 4, sumOfArray = 8;
	int negativeNumbers = 0, sumOfGivenNumbers = 0;

	vector<int> givenArray {1, -1, -1, 3};
	vector<int> arrayOfPositiveNumbers;

	for (int i = 0; i < givenArrayLength; i++) {
		if (givenArray[i] < 0) // Condition to check if given number is negative or not
			negativeNumbers++;
		else {
			sumOfGivenNumbers += givenArray[i];
			arrayOfPositiveNumbers.push_back(givenArray[i]);
		}
	}

	int reamainingSum = sumOfArray - sumOfGivenNumbers;

	if (sumOfGivenNumbers > sumOfArray || reamainingSum < negativeNumbers || givenArrayLength == 1 
		|| (negativeNumbers == 0 && (sumOfArray != sumOfGivenNumbers))) { // Necessary edge cases
		cout << "0" << endl;
		return 0;
	}

	long long answer = 0;

	//Calculation of the GCD of positive numbers
	for (int i = 0; i < (int)arrayOfPositiveNumbers.size(); i++) {
		for (int j = i + 1; j < (int)arrayOfPositiveNumbers.size(); j++) {
			answer = (answer + __gcd(arrayOfPositiveNumbers[i], arrayOfPositiveNumbers[j])) % Modulus;
		}
	}

	if (negativeNumbers == 0) {
		cout << answer << endl;
		return 0;
	}

	if (negativeNumbers == 1) {
		for (int i = 0; i < (int)arrayOfPositiveNumbers.size(); i++) {
				answer = (answer + __gcd(arrayOfPositiveNumbers[i], reamainingSum)) % Modulus;
		}
		cout << answer << endl;
		return 0;
	}
	
	answer = (answer * dp[negativeNumbers][reamainingSum]) % Modulus;
	answer = (answer + gcdAnswer[negativeNumbers][reamainingSum]) % Modulus;

	for (int i = 0; i < (int)arrayOfPositiveNumbers.size(); i++) {
		for (int j = 1; j < N; j++) {
			answer = (answer + __gcd(arrayOfPositiveNumbers[i], j) * numberCount[negativeNumbers][reamainingSum][j]) % Modulus;
		}
	}

	cout << answer << endl;
	return 0;
}
