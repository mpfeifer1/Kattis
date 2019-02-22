#include <bits/stdc++.h>

using namespace std;

// Returns an array with the indexes of the LIS
template <class T>
deque<int> LIS(deque<T>& v) {
    if(v.size() == 0) return {};
    deque<int> p(v.size(), -1);
    deque<int> t(v.size(), 0);

    int lis = 1;
    for(int i = 1; i < v.size(); i++) {
        if(v[i] <= v[t[0]]) {
            t[0] = i;
        }
        else if(v[i] > v[t[lis - 1]]) {
            p[i] = t[lis - 1];
            t[lis++] = i;
        }
        else {
            int l = -1;
            int r = lis - 1;
            while(r - l > 1) {
                int m = l + (r - l) / 2;
                if(v[t[m]] >= v[i]) r = m;
                else l = m;
            }
            p[i] = t[r - 1];
            t[r] = i;
        }
    }

    deque<int> ans;
    for(int i = t[lis - 1]; i >= 0; i = p[i]) {
        ans.push_back(i);
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    int n;
    cin >> n;

    deque<int> d(n);
    for(auto& i : d) {
        cin >> i;
    }

    int ans = 0;
    while(d.size() > 0) {
        int center = d.front();
        d.pop_front();

        deque<pair<int,int>> d1;
        deque<pair<int,int>> d2;

        // Run LSIS ascending, with all greater than the front
        for(auto i : d) {
            if(i > center) {
                int sz = d1.size();
                d1.push_back({i,sz});
            }
        }
        // Run LSIS descending
        for(auto i : d) {
            if(i < center) {
                int sz = d2.size();
                d2.push_back({-i,-sz});
            }
        }

        ans = max(ans,int(1 + LIS(d1).size() + LIS(d2).size()));
    }

    cout << ans << endl;
}
