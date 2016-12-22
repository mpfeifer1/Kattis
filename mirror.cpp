#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        vector<vector<char>> v;
        v.resize(x);

        for(int j = 0; j < x; j++) {
            for(int k = 0; k < y; k++) {
                char temp;
                cin >> temp;
                v[j].push_back(temp);
            }
        }

        cout << "Test " << i+1 << endl;
        for(int j = x-1; j >= 0; j--) {
            for(int k = y-1; k >= 0; k--) {
                cout << v[j][k];
            }
            cout << endl;
        }
    }
}
