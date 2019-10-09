#include <bits/stdc++.h>
using namespace std;

set < long long > fac;
//geeksforgeeks
void printDivisors(long long n) 
{ 
    // Note that this loop runs till square root 
    for (long long i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            // If divisors are equal, prlong long only one 
            if (n/i == i) {
            	fac.insert(i);
            } 
  
            else {
            	fac.insert(i);
            	fac.insert(n / i);
            }// Otherwise prlong long both 
        } 
    } 
} 
  
int main() {
	long long n;
	cin >> n;
	printDivisors(n);
	cout << fac.size() << endl;
	return 0;
}