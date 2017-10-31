#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

bool play(ll a, ll b) {
    // Swap nums
    if(a > b) {
        return play(b, a);
    }

    // Winning move
    if(b % a == 0) {
        return true;
    }

    // Forced move
    if((b/a) == 1) {
        return !play(a, b-a);
    }

    // Normal move
    return true;
}

int main() {
    ll a, b;
    while(cin >> a && cin >> b && !(a == 0 && b == 0)) {
        if(b > a) {
            swap(a, b);
        }

        bool winner = play(a, b);

        if(winner) {
            cout << "Stan wins" << endl;
        }
        else {
            cout << "Ollie wins" << endl;
        }
    }
}
