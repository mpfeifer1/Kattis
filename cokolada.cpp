#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int bar = 1;

    int powerof2 = 0;
    while(bar < n) {
        bar *= 2;
        powerof2++;
    }

    int temp = bar - n;

    vector<int> bits;
    while(temp > 0) {
        if(temp % 2 == 0) {
            bits.push_back(0);
        }
        if(temp % 2 == 1) {
            bits.push_back(1);
        }
        temp >>= 1;
    }

    while(bits.size() < powerof2) {
        bits.push_back(0);
    }

    reverse(bits.begin(), bits.end());

    int breaks = 0;
    for(int i = 0; i < bits.size(); i++) {
        if(bits[i] == 1) {
            breaks = i+1;
        }
    }

    cout << bar << " " << breaks << endl;;
}
