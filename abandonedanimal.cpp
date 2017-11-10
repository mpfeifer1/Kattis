#include <iostream>

using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k;

    // Set up data structures
    unordered_map<string, int> item_to_num;
    vector<vector<int>> adj(n);
    vector<int> items;

    // Read in the first half of the data
    for(int i = 0; i < k; i++) {
        int store;
        string item;
        cin >> store >> item;
        if(item_to_num.count(item) == 0) {
            int size = item_to_num.size();
            item_to_num[item] = size;
        }

        adj[store].push_back(item_to_num[s])
    }

    // Read in the second half
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        string item;
        cin >> item;
        items.push_back(item);
    }
}
