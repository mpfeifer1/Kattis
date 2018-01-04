#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--) {
        int p;
        cin >> p;

        vector<int> v(p*3);
        for(auto& i : v) {
            cin >> i;
        }

        sort(v.rbegin(), v.rend());

        int total = 0;
        for(int i = 0; i < p; i++) {
            total += v[i*2+1];
        }

        cout << total << endl;
    }
}
