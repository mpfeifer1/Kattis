#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

ull bits(ull n) {
    ull ans = 0;
    while(n > 0) {
        if(n % 2 == 1) {
            ans++;
        }
        n >>= 1;
    }
    return ans;
}

ull decrease(ull n, ull k) {
    ull extra = bits(n) - k + 1;

    ull i = 1;
    ull found = 0;

    while(found < extra) {
        if(n & i) {
            found++;
        }

        if(found == extra) {
            n += i;
            break;
        }

        i <<= 1;
    }

    while(i > 0) {
        i >>= 1;
        n &= ~i;
    }

    return n;
}

ull increase(ull n, ull k) {
    ull i = 1;
    ull need = k - bits(n);
    while(need > 0) {
        if((n & i) == 0) {
            n |= i;
            need--;
        }
        i <<= 1;
    }
    return n;
}

int main() {
    ull n, k;
    cin >> n >> k;

    n++;

    if(bits(n) > k) {
        n = decrease(n, k);
    }

    if(bits(n) < k) {
        n = increase(n, k);
    }

    cout << n << endl;
}
