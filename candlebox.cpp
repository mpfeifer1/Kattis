#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> t;
    vector<int> r;
    t.resize(70, 0);
    r.resize(70, 0);

    int d, c1, c2;
    cin >> d >> c1 >> c2;

    for(int i = 0; i < t.size(); i++) {
        if(i >= 3) {
            t[i] = i + t[i-1];
        }
        if(i >= 4) {
            r[i] = i + r[i-1];
        }
    }

    for(int i = d; i < t.size(); i++) {
        if(t[i-d] + r[i] == c1 + c2) {
            cout << c1 - r[i] << endl;
        }
    }
}
