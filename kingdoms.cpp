#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool onebit(ll n) {
    return n && !(n & (n-1));
}

ll getbit(ll n) {
    ll ct = 0;
    while(n > 0) {
        ct++;
        n >>= 1;
    }
    return ct;
}

vector<ll> getallbit(ll n) {
    vector<ll> res;
    ll ct = 0;
    while(n > 0) {
        if(n&1) res.push_back(ct);
        n >>= 1;
        ct++;
    }
    return res;
}

ll unset(ll n, ll bit) {
    return n & ~(1 << bit);
}

struct lex_compare {
    bool operator() (const ll& i1, const ll& i2) {
        if(getbit(i1) == getbit(i2)) {
            return i1 > i2;
        }
        return getbit(i1) > getbit(i2);
    }
};

void getnext(vector<vector<ll>>& v, set<ll, lex_compare>& states, ll curr, ll n) {
    vector<ll> keep = getallbit(curr);

    vector<ll> owe(n,0);
    for(auto i : keep) {
        for(auto j : keep) {
            owe[i] += v[i][j];
        }
    }

    for(auto i : keep) {
        if(owe[i] > 0) {
            states.insert(unset(curr,i));
        }
    }
}

void solve() {
    ll n;
    cin >> n;

    // v[i][j]=x means i owes j x dollars

    // Read in this case
    vector<vector<ll>> v(n, vector<ll>(n));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    // Get starting number
    ll start = 0;
    for(ll i = 0; i != n; i++) {
        start |= (1<<i);
    }

    // Build set of all states
    set<ll, lex_compare> states;
    states.insert(start);

    // Process all possible states
    set<ll> answer;
    while(!states.empty()) {
        ll curr = *states.begin();
        states.erase(curr);

        // If one bit, add it to answer
        if(onebit(curr)) {
            answer.insert(getbit(curr));
            continue;
        }

        // Otherwise, get all 'next' from it
        getnext(v, states, curr, n);
    }

    // Print the answer
    if(answer.size() == 0) {
        cout << "0";
    }
    for(auto i : answer) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    ll cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
