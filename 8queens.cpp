#include <iostream>
#include <vector>

using namespace std;

int main() {
    char ch;
    vector<bool> a;
    vector<bool> b;
    vector<bool> c;
    vector<bool> d;

    a.resize(15, false);
    b.resize(15, false);
    c.resize(8, false);
    d.resize(8, false);

    int queens = 0;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cin >> ch;
            while(ch != '*' && ch != '.') {
                cin >> ch;
            }
            if(ch == '*') {
                queens++;
                if(a[j-i+7] || b[i+j] || c[i] || d[j]) {
                    cout << "invalid" << endl;
                    return 0;
                }
                a[j - i + 7] = true;
                b[i + j] = true;
                c[i] = true;
                d[j] = true;
            }
        }
    }

    if(queens == 8) {
        cout << "valid" << endl;
    }
    else {
        cout << "invalid" << endl;
    }
    return 0;
}
