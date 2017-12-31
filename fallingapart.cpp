#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    sort(v.rbegin(), v.rend());

    int a = 0;
    int b = 0;

    for(int i = 0; i < v.size(); i++) {
        if(i % 2 == 0) {
            a += v[i];
        }
        else {
            b += v[i];
        }
    }

    cout << a << " " << b << endl;
}
