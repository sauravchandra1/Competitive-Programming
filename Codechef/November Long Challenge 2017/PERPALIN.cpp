#include <iostream>
using namespace std;
 
int main() {
    int test; cin >> test;
    while(test--) {
        int num, palin; cin >> num >> palin;
        if(palin == 1 || palin == 2) cout << "impossible" << endl;
        else {
            int s1 = num / palin;
            int s2 = 0;
            while(s1--) { s2 = palin; cout << "a"; s2 -= 2; while(s2--) cout << "b"; cout << "a"; }
            cout << endl;
        }
    }
    return 0;
} 
