#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;

int main() {
    int n, length, variance;
    cin >> n >> length >> variance;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    map<int, int> used;
    deque<int> current;

    for(int i = 0; i < length-1; i++) {
        // Add element
        int element = v[i];
        used[element]++;
        current.push_back(element);
    }

    bool printed = false;
    for(int i = length-1; i < n; i++) {
        // Add element
        int element = v[i];
        used[element]++;
        current.push_back(element);

        /*
        cout << "Line: ";
        for(auto j : current) {
            cout << j << " ";
        }
        cout << endl;
        */

        // Process
        int hi = used.rbegin()->first;
        int lo = used.begin()->first;
        if(hi - lo <= variance) {
            printed = true;
            cout << i-length+2 << endl;
        }

        // Remove element after use
        used[current.front()]--;
        if(used[current.front()] == 0) {
            used.erase(current.front());
        }
        current.pop_front();
    }

    if(!printed) {
        cout << "NONE" << endl;
    }
}
