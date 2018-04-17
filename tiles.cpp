// Michael Pfeifer
// Version 04, 2018/02/17

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ld  pi   = 4.0*atanl(1.0);
const int iinf = 1e9 + 10;
const ll  inf  = 1e18 + 10;
const int mod  = 1000000007;
const ld  prec = .000001;

#define enld endl
#define endl '\n'
#define pb push_back
#define debug(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define umap unordered_map
#define uset unordered_set

template<class TIn>
using indexed_set = tree<
        TIn, null_type, less<TIn>,
        rb_tree_tag, tree_order_statistics_node_update>;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void file() {
    auto a = freopen("a.in",  "r", stdin);
    auto b = freopen("a.out", "w", stdout);
    if(!a || !b) cout << "uh oh" << endl;
}





void nextpow(ll& n) {
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
}

void fft(valarray<complex<double>>& x) {
    ll s = x.size();

    if(s <= 1) {
        return;
    }

    valarray<complex<double>> even = x[slice(0, s/2, 2)];
    valarray<complex<double>> odd  = x[slice(1, s/2, 2)];

    fft(even);
    fft(odd);

    for(ll i = 0; i < s/2; i++) {
        complex<double> t = polar(1.0, -2.0 * M_PI * i / s) * odd[i];
        x[i]     = even[i] + t;
        x[i+s/2] = even[i] - t;
    }
}

void ifft(valarray<complex<double>>& x) {
    x = x.apply(conj);
    fft(x);
    x = x.apply(conj);
    x /= x.size();
}

int div(int n) {
    map<int,int> factors;

    for(int i = 2; i <= sqrt(n); i++) {
        while(n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if(n > 1) {
        factors[n]++;
    }

    int val = 1;
    for(auto i : factors) {
        val *= (i.second + 1);
    }

    return val;
}

int main() {
    //file();
    //fast();

    // CALCULATE SIZE
    ll size = 500000;
    nextpow(size);
    size++;
    nextpow(size);

    // CALCULATE ALL DIVISORS
    vector<int> divisors;
    for(int i = 0; i <= size+2; i++) {
        divisors.pb(div(i));
    }
    divisors[0] = 0;

    // BUILD POLYNOMIAL FROM DIVISORS
    valarray<complex<double>> v1(size);
    valarray<complex<double>> v2(size);
    for(ll i = 0; i < size/2; i++) {
        v1[i] = divisors[i];
    }

    // MULTIPLY POLYNOMIALS
    fft(v1);
    for(ll i = 0; i < size; i++) {
        v1[i] *= v1[i];
    }
    ifft(v1);

    // PROCESS QUERIES
    int q;
    cin >> q;
    while(q--) {
        int n1, n2;
        cin >> n1 >> n2;
        int idx = -1;
        int val = -1;
        for(int i = n1; i <= n2; i++) {
            if(int(v1[i].real()+.25) > val) {
                val = int(v1[i].real()+.25);
                idx = i;
            }
        }

        cout << idx << " " << val << endl;
    }

    return 0;
}
