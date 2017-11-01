#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll n, k, q;
    cin >> n >> k >> q;

    for(ll i = 0; i < q; i++) {
        ll a, b;
        cin >> a >> b;

        ll moves = 0;
        a--;
        b--;
        while(a != b) {
            moves++;
            if(b > a) {
                swap(a, b);
            }

            a--;
            a /= k;
        }

        cout << moves << endl;
    }
}
