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


ll get(vector<ll> v) {
    vector<ll> possible1((60000*4+1),0);
    vector<ll> possible2((60000*4+1),0);
    vector<ll> possible3((60000*4+1),0);
    vector<ll> possible4((60000*4+1),0);
    for(auto i : v) {
        possible1[i] = 1;
        possible2[i] = 1;
        possible3[i] = 1;
        possible4[i] = 1;
    }

    vector<ll> res(60000*4+1,0);
    vector<ll> temp(60000*4+1,0);
    mult(possible1, possible2, res);
    for(ll i = 0; i < (60000*4)+1; i++) temp[i] = res[i];
    mult(temp, possible3, res);
    for(ll i = 0; i < (60000*4)+1; i++) temp[i] = res[i];
    mult(temp, possible4, res);

    ll ways = 0;
    for(auto i : res) {
        if(i > 0) ways++;
    }
    return ways;
}


int main() {
    ll n;
    cin >> n;

    // Read ans
    vector<ll> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    // ll max and min
    sort(v.begin(),v.end());
    cout << v.back()*4 << " " << v.front()*4 << " ";

    // Print distinct weights
    cout << get(v) << " ";

    // Calculate sum of figurines
    ll sum = 0;
    for(auto i : v) {
        sum += i;
    }

    // Print expected value
    cout << fixed;
    cout.precision(6);
    cout << (double)sum * 4 / n << endl;
}
