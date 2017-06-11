#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    while(cin >> n && n != 0) {
        vector<int> l1, l2;

        for(int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            l1.push_back(temp);
        }

        for(int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            l2.push_back(temp);
        }

        vector<int> l1_sorted = l1;
        sort(l1_sorted.begin(), l1_sorted.end());
        sort(l2.begin(), l2.end());

        map<int, int> locations;

        for(int i = 0; i < n; i++) {
            locations[l1_sorted[i]] = i;
        }

        vector<int> ret;

        for(int i = 0; i < n; i++) {
            int pos = locations.find(l1[i])->second;
            ret.push_back(l2[pos]);
        }

        for(auto i : ret) {
            cout << i << endl;
        }

        cout << endl;
    }
}
