#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;

    for(int i = 0; i < n; i++) {
        int price;
        cin >> price;
        v.push_back(price);
    }

    sort(v.rbegin(), v.rend());

    int cost = 0;

    for(int j = 0; j < v.size(); j++) {
        if(j % 3 != 2) {
            cost += v[j];
        }
    }

    cout << cost << endl;
}
