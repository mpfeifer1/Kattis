#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        int n;
        cin >> n;

        priority_queue<ll> q;
        for(int i = 0; i < n; i++) {
            ll c;
            cin >> c;
            q.push(-c);
        }

        ll total = 0;
        while(q.size() >= 2) {
            ll t = 0;
            t += q.top();
            q.pop();
            t += q.top();
            q.pop();
            total += t;
            q.push(t);
        }

        cout << -total << endl;
    }
}
