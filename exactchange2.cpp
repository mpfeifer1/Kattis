#include <iostream>
#include <vector>

using namespace std;

int inf = 2 << 28;

int main() {
    int cases;
    cin >> cases;

    while(cases--) {
        int n;
        cin >> n;

        vector<int> v(10001, inf);
        v[0] = 0;

        int k;
        cin >> k;

        for(int i = 0; i < k; i++) {
            int coin;
            cin >> coin;

            for(int i = 10000 - coin; i >= 0; i--) {
                v[i+coin] = min(v[i+coin], v[i]+1);
            }
        }

        for(int i = n; i <= 10000; i++) {
            if(v[i] < inf/2) {
                cout << i << " " << v[i] << endl;
                break;
            }
        }

    }
}
