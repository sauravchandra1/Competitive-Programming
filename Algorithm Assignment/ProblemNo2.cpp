#include <iostream>
using namespace std;

#define N 100005
#define A 200
#define Modulus 998244353

long long dp[N + 10][A + 10][2];

int main() {
    int arraySize = 3; 
    long long array[] = {1, -1, 2}; // Initital array

    // For first element all the previous element consider smaller than itself
    if (array[0] == -1) 
    	for (int i = 1; i <= A; i++)
    		dp[0][i][0] = 1;
    else
    	dp[0][array[0]][0] = 1;

    for (int i = 1; i < arraySize; i++) {
        // If current element if -1 then calculate all posible answer by filling
        // that position by number from 1 to A
    	if (array[i] == -1) {
    		for (int j = 2; j <= A; j++)
    			dp[i][j][0] = (dp[i][j - 1][0] % Modulus + dp[i - 1][j - 1][0] % Modulus + dp[i - 1][j - 1][1] % Modulus) % Modulus;

    		dp[i][A][1] = dp[i - 1][A][1];

    		for (int j = A - 1; j >= 1; j--) 
    			dp[i][j][1] = (dp[i][j + 1][1] % Modulus + dp[i - 1][j][1] % Modulus) % Modulus;

    		for (int j = A; j >= 1; j--)
    			dp[i][j][1] = (dp[i][j][1] % Modulus + dp[i - 1][j][0] % Modulus) % Modulus; 
    	}
    	else {
            // If current element is not -1 then calculate answer for that perticular element
    		int a = array[i];
                
    		for (int j = 1; j <= a - 1; j++) 
    			dp[i][a][0] = (dp[i][a][0] % Modulus + 
    						dp[i - 1][j][0] % Modulus + dp[i - 1][j][1] % Modulus) % Modulus;
   
    		dp[i][a][1] = dp[i - 1][a][0];
   
    		for (int j = a; j <= A; j++) 
    			dp[i][a][1] = (dp[i][a][1] % Modulus + dp[i - 1][j][1] % Modulus) % Modulus;
  	  	}
    }
    long long answer = 0;
    
    // If last element is -1 then count all the answers that can be possible 
    // by filling last element by number from 1 to A   
   	if (array[arraySize - 1] == -1) 
   		for (int i = 1; i <= A; i++)
   			answer = (answer % Modulus + dp[arraySize - 1][i][1] % Modulus) % Modulus;
   	else
   		answer = dp[arraySize - 1][array[arraySize - 1]][1];
   
   	cout << answer << endl;
    return 0;
}