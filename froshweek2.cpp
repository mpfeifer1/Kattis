#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v1(n);
    vector<int> v2(m);

    for(auto& i : v1) {
        cin >> i;
    }
    for(auto& i : v2) {
        cin >> i;
    }

    sort(v1.rbegin(), v1.rend());
    sort(v2.rbegin(), v2.rend());

    int work = 0;

    int idx1 = 0;
    int idx2 = 0;
    while(idx1 < v1.size() && idx2 < v2.size()) {
        if(v1[idx1] <= v2[idx2]) {
            work++;
            idx2++;
        }
        idx1++;
    }

    cout << work << endl;
}
