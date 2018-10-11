#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod = 10007;

// Converts from 'knight position' to 'grid position'
void convert(ll& i1, ll& i2) {
    ll row = (i1 + i2) / 3;
    i1 -= row;
    i2 -= row;
}

// Helps sort points by their diagonal
bool cmp(pair<ll,ll>& p1, pair<ll,ll>& p2) {
    return (p1.first+p1.second) <
           (p2.first+p2.second);
}

// Calculates a^b%p quickly
ll power(ll a, ll b) {
    if (b <= 0) return 1;
    ll temp = power(a, b / 2) % mod;
    if (b % 2 == 0) {
        return (temp * temp) % mod;
    }
    else {
        return (((a * temp) % mod) * temp) % mod;
    }
}

// Calculates nCr for lower values quickly
struct NchooseK {
    int range;
    vector<ll> fact,ifact;
    NchooseK() {
        range = (int)mod-1;
        fact.resize(range+1);
        ifact.resize(range+1);
        calcFacts();
    }
    void calcFacts() {
        fact[0] = 1;
        for(ll i = 1; i <= range; ++i) {
            fact[i] = (1LL*fact[i-1]*i)%mod;
        }
        ifact[range] = power(fact[range], mod-2);
        for(int i = range-1; i >= 0; --i) {
            ifact[i] = (1LL*ifact[i+1]*(i+1))%mod;
        }
    }
    ll choose(int n, int k) {
        if(k < 0 || k > n || n < 0) return 0;
        return ((1LL*fact[n]*ifact[k])%mod * 1LL*ifact[n-k])%mod;
    }
}nk;


// Computes nCr
vector<vector<int>> memo;
ll choose(ll n, ll r) {
    if(r == 0) {
        return 1;
    }

    int ni = n % mod;
    int ri = r % mod;

    return (choose(n/mod, r/mod) * nk.choose(ni,ri)) % mod;
}

// This function just makes sure modular arithmetic is OK
ll clean(ll n) {
    n %= mod;
    n += mod;
    n %= mod;
    return n;
}

// This function tells if there's a path running
// through these two points
bool validpath(ll x1, ll y1, ll x2, ll y2) {
    if(x1+y1 == x2+y2) return false;
    return ((x1 <= x2) && (y1 <= y2));
}

void solve() {
    // Read in input
    ll n, m, r;
    cin >> n >> m >> r;
    n--;
    m--;

    // Read in all the rocks, keep valid ones
    vector<pair<ll,ll>> rocks;
    for(ll i = 0; i < r; i++) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        if((x+y)%3 == 0) {
            rocks.push_back({x,y});
        }
    }

    // If the end point isn't valid, break out early
    if((n+m)%3 != 0) {
        cout << 0 << endl;
        return;
    }

    // Convert the end point
    convert(n,m);

    // Convert rocks, keep only valid ones
    vector<pair<ll,ll>> temp;
    for(auto i : rocks) {
        convert(i.first, i.second);
        if(i.first < 0 || i.first > n || i.second < 0 || i.second > m) {
            continue;
        }
        temp.push_back(i);
    }
    swap(temp, rocks);
    r = rocks.size();

    // If there are no rocks, print the answer
    if(r == 0) {
        cout << clean(choose(n+m,n)) << endl;
        return;
    }

    // Sort the rocks by their diagonal
    sort(rocks.begin(), rocks.end(), cmp);

    // For each subset,
    ll ways = 0;
    for(ll i = 0; i < (1<<r); i++) {
        // Build the entire subset, always
        // including the start and finish
        vector<pair<ll,ll>> subset;
        subset.push_back({0,0});
        ll parity = 1;
        for(ll j = 0; j < r; j++) {
            if(i & (1<<j)) {
                subset.push_back(rocks[j]);
                parity *= -1;
            }
        }
        subset.push_back({n,m});

        // Process subset
        // We need to connect each rock to the next,
        // and check that each step is valid
        ll wayshere = 1;
        for(ll i = 1; i < subset.size(); i++) {
            // Grab points for ease of use
            ll prevx = subset[i-1].first;
            ll prevy = subset[i-1].second;
            ll currx = subset[i].first;
            ll curry = subset[i].second;

            // Check if these two points are valid
            if(!validpath(prevx, prevy, currx, curry)) {
                wayshere *= 0;
                break;
            }

            // Add the ways for these points
            ll d1 = (currx-prevx);
            ll d2 = (curry-prevy);
            wayshere *= choose(d1+d2, d1);
            wayshere = clean(wayshere);
        }

        // Multiply the ways here by its parity
        wayshere *= parity;
        wayshere = clean(wayshere);

        // Add these ways to the answer
        ways += wayshere;
        ways = clean(ways);
    }

    // Print the answer
    cout << ways << endl;
}

int main() {

    // Process test cases
    ll cases;
    cin >> cases;
    for(ll i = 1; i <= cases; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
