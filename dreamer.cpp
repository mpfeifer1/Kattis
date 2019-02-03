#include <bits/stdc++.h>

using namespace std;

struct date {
    int d, m, y;
};

bool operator<(const date& d1, const date& d2) {
    if(d1.y == d2.y) {
        if(d1.m == d2.m) {
            return d1.d < d2.d;
        }
        return d1.m < d2.m;
    }
    return d1.y < d2.y;
}

bool leap(int y) {
    if(y % 400 == 0) return true;
    if(y % 100 == 0) return false;
    if(y % 4 == 0) return true;
    return false;
}

bool works(date d) {
    if(d.d < 1) return false;
    if(d.m < 1) return false;
    if(d.y < 2000) return false;

    if(d.m > 12) return false;

    vector<int> days = {-1,31,28,31,30,31,30,31,31,30,31,30,31};
    if(leap(d.y)) {
        days[2]++;
    }

    if(d.d > days[d.m]) return false;

    return true;
}

void solve() {
    vector<char> v(8);
    for(int i = 0; i < 8; i++) {
        cin >> v[i];
        if(i == 1 || i == 3) {
            cin.ignore();
        }
    }

    vector<int> perm;
    for(auto i : v) {
        perm.push_back(i-'0');
    }

    sort(perm.begin(),perm.end());
    set<date> good;
    do {
        int d = perm[0] * 10 + perm[1];
        int m = perm[2] * 10 + perm[3];
        int y = perm[4] * 1000 + perm[5] * 100 + perm[6] * 10 + perm[7];
        if(works({d,m,y})) {
            good.insert({d,m,y});
        }
    } while(next_permutation(perm.begin(),perm.end()));

    cout << good.size() << " ";
    if(good.size() > 0) {
        date d = *good.begin();
        if(d.d < 10) cout << "0";
        cout << d.d << " ";
        if(d.m < 10) cout << "0";
        cout << d.m << " ";
        cout << d.y;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        solve();
    }
}
