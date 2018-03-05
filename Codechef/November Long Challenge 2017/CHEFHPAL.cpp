#include <iostream>
using namespace std;
 
int main() {
    int test; cin >> test;
    while(test--) {
        int num, cnt; cin >> num >> cnt;
        char c = 'a';
        if(cnt == 1) {
            cout << num;
            while(num--)
                cout << "a";
            cout << endl;
        }
        if(cnt == 2) {
            if(num == 1) cout << "1 b" << endl;
            else if(num == 2) cout << "1 ba" << endl;
            else if(num == 3) cout << "2 bba" << endl;
            else if(num == 4) cout << "2 bbaa" << endl;
            else if(num == 5) cout << "3 bbbaa" << endl;
            else if(num == 6) cout << "3 bbbaaa" << endl;
            else if(num == 7) cout << "3 aaababb" << endl;
            else if(num == 8) cout << "3 bbbabaaa" << endl;
            else {
                cout << "4 ";
                string str = "aababbaababb";
                int t = num/12;
                while(t--)
                    cout << str;
                t = num % 12 ;
                for(int i = 0;i < t;i++)
                    cout << str[i];
                cout << endl;
            }
        }
        if(cnt > 2) {
            cout <<"1 ";
            while(num--) {
                if((c - 'a' + 1) > cnt)
                    c = 'a';
                cout << c;
                c = c + 1;
            }
            cout << endl;
        }
    }
    return 0;
} 
