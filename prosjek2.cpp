#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
ld eps = .00001;

vector<ld> arr;
bool works(int len, ld avg) {
    vector<ld> temp;
    for(auto& i : arr) {
        temp.push_back(i - avg);
    }

    vector<ld> prefix;
    prefix.push_back(0);
    for(int i = 0; i < temp.size(); i++) {
        prefix.push_back(temp[i] + prefix.back());
    }

    bool good = false;

    ld minpref = prefix[0];
    for(int i = len; i < prefix.size(); i++) {
        minpref = min(prefix[i-len], minpref);
        if(prefix[i] - minpref >= 0) {
            good = true;
            break;
        }
    }

    return good;
}

int main() {
    int n, k;
    cin >> n >> k;
    arr.resize(n);
    for(auto& i : arr) {
        cin >> i;
    }

    ld lo = 0;
    ld hi = 1000001;
    while(hi - lo > eps) {
        ld mi = (hi + lo) / 2;
        if(works(k,mi)) {
            lo = mi;
        }
        else {
            hi = mi;
        }
    }

    cout << fixed;
    cout.precision(6);
    cout << lo << endl;
}
