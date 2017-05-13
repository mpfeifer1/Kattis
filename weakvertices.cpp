#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    while(cin >> n && n != -1) {
        vector<vector<int>> v;
        v.resize(n, vector<int>(n));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }

        // For each node
        for(int i = 0; i < n; i++) {
            bool weak = true;
            // For each of its connections
            for(int j = 0; j < n; j++) {
                // For each of its connections
                for(int k = 0; k < n; k++) {
                    if(v[i][k]==1 && v[i][j]==1 && v[j][k]==1 && i!=k && i!=j && j!=k) {
                        weak = false;
                    }
                }
            }

            if(weak) {
                cout << i << " ";
            }
        }

        cout << endl;
    }
}
