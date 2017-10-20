#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    sort(v.begin(), v.end());

    int charges = 0;

    int location = 0;

    int i;
    for(i = 0; i < v.size(); i++) {
        if(v[i] - charges > v.size() - location) {
            break;
        }
        if(v[i] > charges) {
            charges++;
        }
    }

    charges += v.size() - i;

    cout << charges << endl;
}
