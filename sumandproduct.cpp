#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    // Contains {num,count}
    deque<pair<ll,ll>> v;

    // Read in the numbers and counts
    ll cnt = 0;
    for(ll i = 0; i < n; i++) {
        ll t;
        cin >> t;

        if(t == 1) {
            cnt++;
        }
        else {
            if(cnt > 0) {
                v.push_back({1,cnt});
                cnt = 0;
            }
            v.push_back({t,1});
        }
    }
    if(cnt > 0) {
        v.push_back({1,cnt});
        cnt = 0;
    }

    // Debugging
    /*
    for(auto i : v) {
        cout << i.first << " " << i.second << endl;
    }
    */

    ll ans = 0;

    // For each number, assume it is the start point
    while(v.size() > 0) {
        // With this start point, count all answers until the product becomes too large
        ll sum = 0;
        ll prod = 1;
        for(auto i : v) {
            if(i.first == 1) {
                // Check if there's a possible solution here
                ll onesNeeded = prod - sum;
                if(1 <= onesNeeded && onesNeeded <= i.second) {
                    ans++;
                }

                // Add in the ones
                sum += i.second;
            }
            else {
                // Add in
                sum += i.first;
                prod *= i.first;

                // Check if this created a valid solution
                if(sum == prod) {
                    ans++;
                }

                // If product is too large, quit
                if(prod > n * 4) {
                    break;
                }
            }
        }

        // Remove the first element of the array
        if(v.front().second > 1) {
            v.front().second--;
        }
        else {
            v.pop_front();
        }
    }

    cout << ans - n << endl;
}
