#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> count;
    count.resize(11, 0);

    for(auto c : s) {
        count[c-'0']++;
    }

    count[10] = count[0];

    int num = 1;
    int m = count[1];
    for(int i = 1; i <= 10; i++) {
        if(count[i] < m) {
            num = i;
        }
        m = min(m, count[i]);
    }

    if(num == 10) {
        cout << 1;
        num = 0;
    }

    for(int i = 0; i < m+1; i++) {
        cout << num;
    }

    cout << endl;
}
