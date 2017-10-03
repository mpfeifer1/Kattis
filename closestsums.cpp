#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    int count = 1;
    while(cin >> n) {
        cout << "Case " << count << ":" << endl;
        count++;

        vector<int> v;
        v.resize(n);

        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int m;
        cin >> m;

        for(int i = 0; i < m; i++) {
            int target;
            cin >> target;
            int closest = v[0]+v[1];

            for(int j = 0; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    int sum = v[j] + v[k];
                    if(abs(sum - target) < abs(closest - target)) {
                        closest = sum;
                    }
                }
            }

            cout << "Closest sum to " << target << " is " << closest << "." << endl;
        }
    }
}
