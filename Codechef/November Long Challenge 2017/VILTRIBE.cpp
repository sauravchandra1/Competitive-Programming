#include <iostream>
using namespace std;
 
int main() {
    int test; cin >> test;
    while(test--) {
        string stringg; cin >> stringg;
        int numa = 0, ex = 0, flag = 0, numb = 0;
        for(int i = 0;i < stringg.size();i++) {
            if (stringg[i] == 'A' && !flag) { numa++; flag = 1; }
            else if (flag && stringg[i] == 'B') { ex = 0; flag = 0; }
            else if(flag && stringg[i] == '.') ex++;
            else if(flag && stringg[i] == 'A') { numa += ex + 1; ex = 0; }
        }
        flag = 0, ex = 0;
        for(int i = 0;i < stringg.size();i++) {
            if (stringg[i] == 'B' && !flag) { numb++; flag = 1; }
            else if (flag && stringg[i] == 'A') { ex = 0; flag = 0; }
            else if(flag && stringg[i] == '.')ex++;
            else if(flag && stringg[i] == 'B') { numb += ex + 1;ex = 0; }
        }
        cout << numa << " " << numb << endl;
    }
    return 0;
} 
