#include <iostream>
#include <vector>

using namespace std;

int main() {
    int r, n;
    cin >> r >> n;

    vector<bool> v;
    v.resize(n+1, false);

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v[temp] = true;
    }

    if(n >= r) {
        cout << "too late" << endl;
    }
    else {
        for(int i = 1; i < r+1; i++) {
            if(!v[i]) {
                cout << i << endl;
                break;
            }
        }
    }
}
