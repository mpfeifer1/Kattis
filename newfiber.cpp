#include <bits/stdc++.h>

using namespace std;

int main() {
    // Fast IO
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // Read in input
    int n, m;
    cin >> n >> m;
    vector<int> deg(n,0);
    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        deg[n1]++;
        deg[n2]++;
    }

    // Store nodes as {degree, num}
    set<pair<int,int>> joined;
    set<pair<int,int>> unjoined;

    vector<int> ones;

    for(int i = 0; i < n; i++) {
        if(deg[i] == 1) {
            ones.push_back(i);
        }
        else {
            unjoined.insert({deg[i], i});
        }
    }

    // Edge case where all have degree 1
    if(unjoined.size() == 0) {
        cout << 0 << endl;
        cout << 2 << " " << 1 << endl;
        cout << 0 << " " << 1 << endl;
        return 0;
    }

    // Define list of edges
    vector<pair<int,int>> edges;

    // Process
    int satisfied = 0;

    // Start out chain
    joined.insert(*unjoined.begin());
    unjoined.erase(*unjoined.begin());

    // Repeatedly satisfy lowest non-1
    while(!unjoined.empty()) {
        // Save the first used node
        int n1 = (*joined.begin()).second;

        // Decrement its degree in joined
        pair<int,int> temp = *joined.begin();
        joined.erase(temp);
        temp.first--;
        joined.insert(temp);

        // If its degree is zero, remove it
        if((*joined.begin()).first == 0) {
            joined.erase((*joined.begin()));
            satisfied++;
        }

        // Decrement degree, and move from unjoined to joined
        pair<int,int> here = (*unjoined.begin());
        int n2 = here.second;
        unjoined.erase(here);
        here.first--;
        joined.insert(here);

        // Add edge
        edges.push_back({n1, n2});
    }

    // Connect all 1's to last node
    for(auto i : ones) {
        edges.push_back({i, (*joined.begin()).second});

        pair<int,int> temp = *joined.begin();
        joined.erase(temp);
        temp.first--;
        if(temp.first > 0 || joined.size() == 0) {
            joined.insert(temp);
        }

        satisfied++;
    }

    // Calculate new degrees
    vector<int> newdeg(n, 0);
    for(auto i : edges) {
        newdeg[i.first]++;
        newdeg[i.second]++;
    }

    // Count matching degrees
    int changes = 0;
    for(int i = 0; i < n; i++) {
        if(deg[i] != newdeg[i]) {
            changes++;
        }
    }

    // Print answer
    cout << changes << endl;
    cout << n << " " << n-1 << endl;
    for(auto i : edges) {
        cout << i.first << " " << i.second << endl;
    }
}
