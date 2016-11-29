#include <iostream>
#include <vector>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    for(int i = 0; i < cases; i++) {
        int dominos, lines;
        cin >> dominos >> lines;
        vector<int> d;
        d.resize(dominos+1, 0);
        for(int j = 0; j < lines; j++) {
            int k, l;
            cin >> k >> l;
            d[k]++;
            d[l]++;
        }
        int ones = 0;
        int zeroes = 0;
        int overflow = 0;
        for(int j = 1; j <= dominos; j++) {
            if(d[j] == 1) {
                ones++;
            }
            else if(d[j] == 0) {
                zeroes++;
            }
            else if(d[j] > 2) {
                overflow += d[j] - 2;
            }
        }
        cout << (ones/2) + zeroes - (overflow/2) << endl;
    }
}
