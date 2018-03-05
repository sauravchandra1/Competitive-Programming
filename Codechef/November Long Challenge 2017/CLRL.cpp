#include <iostream>
using namespace std;
 
int main() {
    int test; cin >> test;
    while(test--) {
        int store[1000006], up_bound = 1111111111;
        int num, val, lw_bound = 0, flag = 0; cin >> num >> val;
        for(int i = 0;i < num;i++) cin >> store[i];
        for(int i = 0;i < num - 1;i++) {
            if(val < store[i]) {
                if(!(store[i] < up_bound && store[i] > lw_bound)) { flag = 1; break; }
                up_bound = store[i];
            }
            else if(store[i] < val) {
                if (!(store[i] > lw_bound && store[i] < up_bound)) { flag = 1; break; }
                lw_bound = store[i];
            }
        }
        if(!flag) cout << "YES" << endl; else cout << "NO" << endl;
    }
    return 0;
} 
