#include <bits/stdc++.h>

using namespace std;
int inf = 1 << 30;

int main() {
    int n, k;
    cin >> n >> k;

    // Set up data structures
    unordered_map<string, set<int>> m;
    vector<int> items;

    // Read in the first half of the data
    for(int i = 0; i < k; i++) {
        int store;
        string item;
        cin >> store >> item;
        m[item].insert(store);
    }

    // Keep track of input
    vector<string> input;

    // Read in the second half
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        string item;
        cin >> item;
        input.push_back(item);
    }

    // Get max from lo to hi
    int maxhere = 0;
    for(int i = 0; i < q; i++) {
        string curr = input[i];
        vector<int> rem;
        for(auto i : m[curr]) {
            if(i < maxhere) {
                rem.push_back(i);
            }
        }
        for(auto i : rem) {
            m[curr].erase(i);
        }
        if(m[curr].size() > 0) {
            maxhere = max(*m[curr].begin(), maxhere);
        }
    }

    // Get min from hi to lo
    int minhere = inf;
    for(int i = q-1; i >= 0; i--) {
        string curr = input[i];
        vector<int> rem;
        for(auto i : m[curr]) {
            if(i > minhere) {
                rem.push_back(i);
            }
        }
        for(auto i : rem) {
            m[curr].erase(i);
        }
        if(m[curr].size() > 0) {
            minhere = min(*m[curr].rbegin(), minhere);
        }
    }

    // Find answer
    bool works = true;
    bool ambig = false;
    for(auto i : input) {
        if(m[i].size() < 1) {
            works = false;
        }
        if(m[i].size() > 1) {
            ambig = true;
        }
    }

    // Print answer
    if(!works) {
        cout << "impossible" << endl;
    }
    else if(ambig) {
        cout << "ambiguous" << endl;
    }
    else {
        cout << "unique" << endl;
    }
}
