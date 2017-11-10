#include <algorithm>
#include <iostream>
#include <valarray>
#include <complex>

using namespace std;

void nextpow(int& n) {
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
}

void fft(valarray<complex<double>>& x) {
    int s = x.size();

    if(s <= 1) {
        return;
    }

    valarray<complex<double>> even = x[slice(0, s/2, 2)];
    valarray<complex<double>> odd  = x[slice(1, s/2, 2)];

    fft(even);
    fft(odd);

    for(int i = 0; i < s/2; i++) {
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

int main() {
    valarray<complex<double>> s1;
    vector<int> v1;

    int size1;
    cin >> size1;
    for(int i = 0; i < size1; i++) {
        int n;
        cin >> n;
        v1.push(n);
    }

    int size2;
    cin >> size2;
}
