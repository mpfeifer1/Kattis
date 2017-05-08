#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        vector<int> g;
        vector<int> m;

        int gSize;
        int mSize;
        cin >> gSize;
        cin >> mSize;

        for(int i = 0; i < gSize; i++) {
            int temp;
            cin >> temp;
            g.push_back(temp);
        }

        for(int i = 0; i < mSize; i++) {
            int temp;
            cin >> temp;
            m.push_back(temp);
        }

        sort(g.begin(), g.end());
        sort(m.begin(), m.end());

        int g1 = 0;
        int m1 = 0;
        while(g1 < gSize && m1 < mSize) {
            if(g[g1] < m[m1]) {
                g1++;
            }
            else {
                m1++;
            }
        }

        if(g1 == gSize) {
            cout << "MechaGodzilla" << endl;
        }
        else {
            cout << "Godzilla" << endl;
        }
    }
}
