#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;

        ans <<= 1;
        if( c == 'O') {
            ans++;
        }
    }
    cout << ans << endl;
}

