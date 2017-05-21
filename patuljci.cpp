#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    int sum = 0;

    for(int i = 0; i < 9; i++) {
        int temp;
        cin >> temp;

        sum += temp;
        v.push_back(temp);
    }

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(i != j && sum - v[i] - v[j] == 100) {
                for(auto n : v) {
                    if(n != v[i] && n != v[j]) {
                        cout << n << endl;
                    }
                }
                return 0;
            }
        }
    }
}
