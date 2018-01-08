#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct event {
    ll s, e;
};

bool cmp(event& e1, event& e2) {
    if(e1.e == e2.e) {
        return e1.s < e2.s;
    }
    return e1.e < e2.e;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    event v[n];
    for(int i = 0; i < n; i++) {
        cin >> v[i].s >> v[i].e;
    }
    sort(v, v+n, cmp);

    int ans = 0;
    multiset<int> endtime;
    for(int i = 0; i < n; i++) {
        auto it = endtime.lower_bound(-v[i].s);

        // If it starts before all end times
        if(it == endtime.end()) {

            // If more classrooms, add
            if(endtime.size() < k) {
                endtime.insert(-v[i].e-1);
                ans++;
            }
            continue;
        }

        // Remove one that ends right before this and add this
        endtime.erase(it);
        endtime.insert(-v[i].e-1);
        ans++;
    }

    cout << ans << endl;
}
