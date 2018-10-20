#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(const int& i1, const int& i2) {
    return i1 > i2;
}

void solve() {
    int n, t, e;
    cin >> n >> t >> e;
    t--;

    vector<deque<int>> towns(n);
    for(int i = 0; i < e; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        towns[n1-1].push_back(n2);
    }

    bool works = true;
    vector<int> ans(n, 0);

    for(int i = 0; i < n; i++) {
        if(i == t) continue;

        int cars = 0;

        sort(towns[i].begin(), towns[i].end(), cmp);
        while(towns[i].size() > 0) {
            if(towns[i].front() == 0) {
                works = false;
                break;
            }
            else {
                cars++;

                int rem = towns[i].front()-1;
                towns[i].pop_front();

                while(rem-- && towns[i].size() > 0) {
                    towns[i].pop_back();
                }
            }
        }

        ans[i] = cars;
    }

    if(works) {
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int cases;
    cin >> cases;
    for(int i = 1; i <= cases; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
