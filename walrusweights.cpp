#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<bool> possible;
    possible.resize(2200, false);
    possible[0] = true;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int weight;
        cin >> weight;
        for(int j = possible.size()-weight-1; j >= 0; j--) {
            if(possible[j]) {
                possible[j+weight] = true;
            }
        }

    }

    int closest = 0;
    for(int j = 0; j < possible.size(); j++) {
        if(possible[j] && abs(1000-j) <= abs(1000-closest)) {
            closest = j;
        }
    }

    cout << closest << endl;
}
