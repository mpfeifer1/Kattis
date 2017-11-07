#include <iostream>
#include <valarray>
#include <complex>
#include <vector>
#include <cmath>

using namespace std;



int nextpow(int n) {
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;

    return n;
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
    int cases;
    cin >> cases;

    while(cases--) {
        int s1;
        cin >> s1;
        s1++;
        vector<complex<double>> temp1(s1);
        for(int i = 0; i < s1; i++) {
            double temp;
            cin >> temp;
            temp1[i] = {temp, 0};
        }

        int s2;
        cin >> s2;
        s2++;
        vector<complex<double>> temp2(s2);
        for(int i = 0; i < s2; i++) {
            double temp;
            cin >> temp;
            temp2[i] = {temp, 0};
        }

        int size = s1 + s2 - 1;
        size = nextpow(size);

        valarray<complex<double>> v1(size);
        valarray<complex<double>> v2(size);
        for(int i = 0; i < s1; i++) {
            v1[i] = temp1[i];
        }
        for(int i = 0; i < s2; i++) {
            v2[i] = temp2[i];
        }

        fft(v1);
        fft(v2);

        valarray<complex<double>> v3(size);
        for(int i = 0; i < v3.size(); i++) {
            v3[i] = v1[i] * v2[i];
        }

        ifft(v3);

        cout << s1+s2-2 << endl;
        for(int i = 0; i < s1+s2-1; i++) {
            int num = ceil(v3[i].real()-.00001);
            cout << num << " ";
        }
        cout << endl;
    }
}
