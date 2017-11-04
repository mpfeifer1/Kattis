#include <iostream>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    for(int i = 0; i < a.size(); i++) {
        int idx = i % b.size();

        int val = (a[i] - 'A') - (b[idx] - 'A');
        if(val >= 26) {
            val -= 26;
        }
        if(val < 0) {
            val += 26;
        }

        a[i] = val + 'A';
        b[idx] = a[i];
    }

    cout << a << endl;
}
