#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 60;

void solve() {
    ll n;
    cin >> n;

    // Read input
    vector<ll> locate(n+1);
    vector<ll> height(n+1);
    for(ll i = 1; i <= n; i++) cin >> locate[i];
    for(ll i = 1; i <= n; i++) cin >> height[i];

    // Prepare preprocessing
    stack<pair<ll,ll>> prevheights;
    prevheights.push({inf,-1});
    vector<ll> needed(n+1,0); // Needed to fill, not overflow

    // Run preprocessing
    for(ll i = 1; i <= n; i++) {
        // You'll need water from prev segments
        needed[i] += needed[i-1];

        ll currh = height[i];
        ll currw = locate[i];
        ll currl = 0;

        while(true) {
            ll prevh = prevheights.top().first;
            ll prevw = prevheights.top().second;

            // If our height is shorter
            if(prevh > currh) {
                ll h = (currh - currl);
                ll w = (currw - prevw - 1);
                needed[i] += w * h;
                break;
            }

            // If our height is taller
            ll h = (currh - currl);
            ll w = (currw - prevw - 1);
            needed[i] += w * h;

            currl = max(prevh, currl);
            currw = prevw + 1;
            prevheights.pop();
        }


        // Add this wall to the stack of walls
        prevheights.push({height[i],locate[i]});
    }

    // Debugging print
    /*
    for(auto i : needed) {
        cout << i << " ";
    }
    cout << endl;
    */

    // Run queries
    ll q;
    cin >> q;
    while(q--) {
        ll t;
        cin >> t;

        // Binary search on t, print answer
        auto it = lower_bound(needed.begin(), needed.end(), t);
        cout << max((int)distance(needed.begin(),it)-1,0) << endl;
    }
}

int main() {
    ll cases;
    cin >> cases;

    while(cases--) {
        solve();
    }
}
