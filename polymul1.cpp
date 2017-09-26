#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Make input faster
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;

    for(int i = 0; i < cases; i++) {
        vector<int> v1;
        vector<int> v2;
        vector<int> v3;

        // Take in the first polynomial
        int size1;
        cin >> size1;
        size1++;
        for(int j = 0; j < size1; j++) {
            int temp;
            cin >> temp;
            v1.push_back(temp);
        }

        // Take in the second polynomial
        int size2;
        cin >> size2;
        size2++;
        for(int j = 0; j < size2; j++) {
            int temp;
            cin >> temp;
            v2.push_back(temp);
        }

        // Create the third polynomial
        int size3 = size1 + size2 - 2;
        v3.resize(size3+1, 0);
        for(int j = 0; j < v1.size(); j++) {
            for(int k = 0; k < v2.size(); k++) {
                v3[j+k] += v1[j] * v2[k];
            }
        }

        cout << size3 << '\n';
        for(auto i : v3) {
            cout << i << " ";
        }
        cout << '\n';
    }
}
