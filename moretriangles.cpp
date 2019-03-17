#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
typedef complex<ld> cd;

const int Max = 1048576;
int bound, logBound;
const ld pi = 4*atan(1.0);
cd root[Max], arrA[Max], arrB[Max];
int perm[Max];
ll prod[Max];

inline void fft(cd* arr) {
    for(int i = 0; i < bound; i++) {
        if(i < perm[i]) {
            swap(arr[i], arr[perm[i]]);
        }
    }
    for(int len = 1; len < bound; len *= 2) {
        for(int pos = 0; pos < bound; pos += 2 * len) {
            for(int i = 0; i < len; i++) {
                cd x = arr[pos + i], y = arr[pos + i + len] * root[bound / len / 2 * i];
                arr[pos + i] = x + y;
                arr[pos + i + len] = x - y;
            }
        }
    }
}

inline void preCalc() {
    int hb = -1;
    root[0] = 1;
    ld angle = 2 * pi / bound;
    for(int i = 1; i < bound; i++) {
        if((i & (i - 1)) == 0) hb++;
        root[i] = cd(cos(angle * i), sin(angle * i));
        perm[i] = perm[i ^ (1 << hb)] + (1 << (logBound - hb - 1));
    }
}

inline void mult(vector<int> &a, vector<int> &b, vector<ll> &c) {
    logBound = 0;
    while((1<<logBound) < a.size() || (1<<logBound) < b.size()) logBound++;
    logBound++;
    bound = (1<<logBound);
    preCalc();
    for(int i = 0; i < a.size(); i++) {
        arrA[i] = cd(a[i], 0);
    }
    for(int i = a.size(); i < bound; i++) {
        arrA[i] = cd(0, 0);
    }
    for(int i = 0; i < b.size(); i++) {
        arrB[i] = cd(b[i], 0);
    }
    for(int i = b.size(); i < bound; i++) {
        arrB[i] = cd(0, 0);
    }
    fft(arrA);
    fft(arrB);
    for(int i = 0; i < bound; i++) {
        arrA[i] *= arrB[i];
    }
    fft(arrA);
    reverse(arrA + 1, arrA + bound);
    c.resize(bound);
    for(int i = 0; i < bound; i++) {
        arrA[i] /= bound;
        ll temp = (arrA[i].real() > 0 ? arrA[i].real()+.5 : arrA[i].real() - .5);
        c[i] = temp;
    }
    while(c.size() && c.back() == 0) c.pop_back();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    // Ways to a^2 and ways to do b^2
    vector<int> a(n+1,0);
    for(int i = 1; i < n; i++) {
        a[(ll(i)*i)%n]++;
    }

    // Ways to do a^2 + b^2
    vector<ll> ab;
    mult(a,a,ab);

    // Ways to do a^2 + b^2 mod n
    vector<ll> v(n,0);
    for(int i = 0; i < ab.size(); i++) {
        v[i%n] += ab[i];
    }

    // Remove all ways where numbers are the same
    for(int i = 1; i < n; i++) {
        v[(2ll*i*i)%n]--;
    }

    // This is all ways to do a^2 + b^2, it doesn't
    // guarantee that a < b
    // So here, we only single-count things
    for(auto& i : v) {
        i /= 2;
    }

    // Add back in ways where numbers are the same
    for(int i = 1; i < n; i++) {
        v[(2ll*i*i)%n]++;
    }

    // Ways to do a^2 + b^2 = c^2 (mod n)
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (ll)v[i] * a[i];
    }

    cout << ans << endl;
}
