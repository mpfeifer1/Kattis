#include <bits/stdc++.h>

using namespace std;

bool works(int n) {
    int tmp = n;
    vector<int> cnt(10,0);
    while(n > 0) {
        if((n%10) == 0) return false;
        if(tmp % (n%10) != 0) return false;
        cnt[n%10]++;
        n /= 10;
    }
    for(auto i : cnt) {
        if(i > 1) return false;
    }
    return true;
}

int main() {
    int lo, hi;
    cin >> lo >> hi;

    int total = 0;
    for(int i = lo; i <= hi; i++) {
        if(works(i)) {
            total++;
        }
    }

    cout << total << endl;
}
