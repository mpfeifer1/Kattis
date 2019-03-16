#include <bits/stdc++.h>

using namespace std;

map<int,int> m;
vector<int> v;
vector<int> l;
vector<int> r;

bool ok(int le, int ri) {
    if(le >= ri) return true;

    // For each spot we can split, if that index is already
    // repeated on the left or right side, solve their subranges
    // instead, skipping that number
    for(int i = le, j = ri; i <= j; i++, j--) {
        if(l[i] < le && r[i] > ri) return ok(le, i-1) && ok(i+1,ri);
        if(l[j] < le && r[j] > ri) return ok(le, j-1) && ok(j+1,ri);
    }

    return false;
}

void solve() {
    m.clear();
    v.clear();
    l.clear();
    r.clear();

    int n;
    cin >> n;

    v.resize(n);
    for(auto& i : v) {
        cin >> i;
    }

    // These tables let you jump left or right to the
    // next instance of that number
    l.resize(n,0);
    r.resize(n,0);

    for(int i = 0; i < n; i++) {
        if(m.count(v[i])) {
            l[i] = m[v[i]];
        }
        else {
            l[i]--;
        }
        m[v[i]] = i;
    }

    m.clear();

    for(int i = n-1; i >= 0; i--) {
        if(m.count(v[i])) {
            r[i] = m[v[i]];
        }
        else {
            r[i] = n;
        }
        m[v[i]] = i;
    }

    if(ok(0,n-1)) {
        cout << "non-boring" << endl;
    }
    else {
        cout << "boring" << endl;
    }
}

int main() {
    int cases;
    cin >> cases;

    while(cases--) {
        solve();
    }
}
