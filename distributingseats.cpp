#include <bits/stdc++.h>

using namespace std;

struct seg {
    int start, end;
};

bool cmp(seg& s1, seg& s2) {
    if(s1.end == s2.end) {
        return s1.start > s2.start;
    }
    return s1.end < s2.end;
}

int main() {
    int n, r, c;
    cin >> n >> r >> c;

    vector<seg> v;

    for(int i = 0; i < n; i++) {
        int row, col, range;
        cin >> row >> col >> range;
        seg s = {row - range, row + range};
        s.start = max(s.start, 1);
        s.end = min(s.end, r);
        v.push_back(s);
    }

    sort(v.begin(), v.end(), cmp);

    map<int,int> rem;
    for(int i = 1; i <= r; i++) {
        rem[i] = c;
    }

    int ans = 0;
    for(auto i : v) {
        auto it = rem.lower_bound(i.start);
        if(it != rem.end() && it->first <= i.end) {
            ans++;
            it->second--;
            if(it->second == 0) {
                rem.erase(it);
            }
        }
    }

    cout << ans << endl;
}
