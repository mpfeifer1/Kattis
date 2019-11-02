#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef complex<double> cd;

const ll Max = 1e6+10;
ll bound, logBound;
const double pi = 4*atan(1.0);
cd root[Max], arrA[Max], arrB[Max];
ll perm[Max];
ll prod[Max];

void fft(cd* arr) {
    for(ll i = 0; i < bound; i++) {
        if(i < perm[i]) {
            swap(arr[i], arr[perm[i]]);
        }
    }
    for(ll len = 1; len < bound; len *= 2) {
        for(ll pos = 0; pos < bound; pos += 2 * len) {
            for(ll i = 0; i < len; i++) {
                cd x = arr[pos + i], y = arr[pos + i + len] * root[bound / len / 2 * i];
                arr[pos + i] = x + y;
                arr[pos + i + len] = x - y;
            }
        }
    }
}

void preCalc() {
    ll hb = -1;
    root[0] = 1;
    double angle = 2 * pi / bound;
    for(ll i = 1; i < bound; i++) {
        if((i & (i - 1)) == 0) hb++;
        root[i] = cd(cos(angle * i), sin(angle * i));
        perm[i] = perm[i ^ (1 << hb)] + (1 << (logBound - hb - 1));
    }
}

void mult(vector<ll> &a, vector<ll> &b, vector<ll> &c) {
    logBound = 0;
    while((1<<logBound) < a.size() || (1<<logBound) < b.size()) logBound++;
    logBound++;
    bound = (1<<logBound);
    preCalc();
    for(ll i = 0; i < a.size(); i++) {
        arrA[i] = cd(a[i], 0);
    }
    for(ll i = a.size(); i < bound; i++) {
        arrA[i] = cd(0, 0);
    }
    for(ll i = 0; i < b.size(); i++) {
        arrB[i] = cd(b[i], 0);
    }
    for(ll i = b.size(); i < bound; i++) {
        arrB[i] = cd(0, 0);
    }
    fft(arrA);
    fft(arrB);
    for(ll i = 0; i < bound; i++) {
        arrA[i] *= arrB[i];
    }
    fft(arrA);
    reverse(arrA + 1, arrA + bound);
    c.resize(bound);
    for(ll i = 0; i < bound; i++) {
        arrA[i] /= bound;
        ll temp = (arrA[i].real() > 0 ? arrA[i].real()+.5 : arrA[i].real() - .5);
        c[i] = temp;
    }
    while(c.size() && c.back() == 0) c.pop_back();
}

ll ADD = 50001;

int main() {
    ll n;
    cin >> n;

    // Count Zeros
    int zeroes = 0;

    // Memory for FFT Arrays
    vector<ll> freq(200008,0);
    vector<ll> res;

    // Keep input
    vector<ll> all;

    // Input
    for(ll i = 0; i < n; i++) {
        ll t; cin >> t;
        // Add "ADD" to all numbers so that there's no negatives
	all.push_back(t+ADD);
        // Frequency represents count of each unique number
        freq[t+ADD]++;
        // Count zeros
        if(t == 0) zeroes++;
    }

    // Multiply frequency by itself (represents frequency of unique numbers after adding
    // all numbers to all other numbers
    mult(freq,freq,res);

    // For each number, remove it added to itself (basically, don't allow i+i=k. only i+j=k)
    for(auto t : all) {
        res[t*2]--;
    }

    // Answer - for each number in the input, add the number of ways
    // we can add two numbers to get it
    ll ans = 0;
    for(auto t : all) {
        ans += res[t+ADD];
    }

    // Remove the number of ways zeros can be added to all other numbers
    ans -= (ll)2 * zeroes * (n-1);

    cout << ans << endl;
}
