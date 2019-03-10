#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, k;
ll inf = (ll)1 << 60;
ll states;

struct card {
    ll w, h, q;
};

vector<ll> cost;
vector<vector<ll>> memo;
vector<card> cards;

ll solve(ll envelopes, ll state) {
    // If in memo, use that
    if(memo[envelopes][state] < inf) {
        return memo[envelopes][state];
    }

    // Base case - no cards left (cost is 0);
    if(state == 0) {
        return memo[envelopes][state] = 0;
    }

    // Base case - no envelopes left, but cards left
    // (cost is infinity)
    if(envelopes == 0) {
        return inf;
    }

    ll ans = inf;
    // For each submask here, recurse on that state
    for(ll s = state; s; s = (s-1)&state) {
        ll anshere = cost[s] + solve(envelopes-1,state^s);
        ans = min(ans, anshere);
    }

    return memo[envelopes][state] = ans;
}

int main() {
    cin >> n >> k;

    cards.resize(n);
    for(auto& i : cards) {
        cin >> i.w >> i.h >> i.q;
    }

    states = 1 << n;

    // Preprocessing - for each combination of cards,
    // calculate the cost if we stuff them all into the same
    // envelope
    cost.resize(states, inf);
    for(ll i = 0; i < states; i++) {
        // Find the largest width and height we need to hold
        ll w = 0;
        ll h = 0;
        for(ll j = 0; j < n; j++) {
            if(i & (1 << j)) {
                w = max(w,cards[j].w);
                h = max(h,cards[j].h);
            }
        }

        // Calculate the waste for each card we're using
        ll costhere = 0;
        for(ll j = 0; j < n; j++) {
            if(i & (1 << j)) {
                ll area = (w*h) - (cards[j].w * cards[j].h);
                costhere += area * cards[j].q;
            }
        }

        // Set the cost
        cost[i] = costhere;
    }


    // Solve the problem
    memo.resize(k+1,vector<ll>(states,inf));
    ll ans = solve(k,states-1);
    cout << ans << endl;
}
