#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll inf = (ll)1 << 60;

vector<ll> primes;

void getprimes(ll n) {
    vector<bool> p(n, true);
    p[0] = false;
    p[1] = false;
    for(ll i = 0; i < n; i++) {
        if(p[i]) {
            primes.push_back(i);
            for(ll j = i*2; j < n; j+=i) {
                p[j] = false;
            }
        }
    }
}

set<ll> factorize(ll n) {
    set<ll> factors;
    for(ll i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            factors.insert(i);
            while(n % i == 0) {
                n /= i;
            }
        }
    }
    if(n > 1) {
        factors.insert(n);
    }
    return factors;
}

set<ll> join(set<ll>& s1, set<ll>& s2) {
    set<ll> end;
    for(auto i : s1) {
        if(s2.count(i) > 0) {
            end.insert(i);
        }
    }
    return end;
}

ll lastin(set<ll>& s) {
    if(s.size() == 0) return 0;
    return *(prev(s.end()));
}

bool works(vector<set<ll>>& facts, ll prime, ll partitions) {
    ll partshere = 1;
    set<ll> curr = facts[0];
    for(ll i = 1; i < facts.size(); i++) {
        set<ll> next = join(curr, facts[i]);
        if(lastin(next) >= prime) {
            curr = next;
        }
        else {
            curr = facts[i];
            partshere++;
        }
    }

    return partshere <= partitions;
}

int main() {
    getprimes(1000000);

    ll n, k;
    cin >> n >> k;

    vector<ll> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    vector<set<ll>> facts(n);
    for(ll i = 0; i < v.size(); i++) {
        facts[i] = factorize(v[i]);
    }

    ll lo = -1;
    ll hi = primes.size();

    ll ans = -1;

    while(hi - lo > 1) {
        ll mi = (hi + lo) / 2;

        if(works(facts, primes[mi], k)) {
            ans = max(ans, mi);
            lo = mi;
        }
        else {
            hi = mi;
        }
    }

    if(ans == -1) {
        cout << 0 << endl;
    }
    else {
        cout << primes[ans] << endl;
    }
}
