#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct query {
    int l, r;
    char op;
};

int find(vector<int>& disjoint, int a) {
    if(disjoint[a] == -1) {
        return a;
    }

    int tmp = find(disjoint, disjoint[a]);
    disjoint[a] = tmp;
    return tmp;
}

void join(vector<int>& disjoint, int a, int b) {
    a = find(disjoint, a);
    b = find(disjoint, b);

    if(a == b) {
        return;
    }

    disjoint[b] = a;
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    // Read in all the queries
    vector<query> equal;
    vector<query> compare;
    for(int i = 0; i < m; i++) {
        query q;
        cin >> q.l >> q.op >> q.r;

        if(q.op == '=') {
            equal.push_back(q);
        }
        else {
            compare.push_back(q);
        }
    }

    // Build disjoint set of players
    vector<int> disjoint(n, -1);
    for(int i = 0; i < equal.size(); i++) {
        join(disjoint, equal[i].l, equal[i].r);
    }

    // Make easy conversions between actual and index
    unordered_map<int, int> ActualToIdx;
    int size = 0;
    for(unsigned int i = 0; i < disjoint.size(); i++) {
        int actual = find(disjoint, i);
        if(ActualToIdx.count(actual) == 0) {
            ActualToIdx[actual] = size;
            size++;
        }
    }

    // Build adjacency matrix
    vector<vector<int>> adj;
    adj.resize(size);

    // Run queries
    for(auto i : compare) {
        int x = ActualToIdx[find(disjoint, i.l)];
        int y = ActualToIdx[find(disjoint, i.r)];
        adj[x].push_back(y);
    }

    // Prepare the Topo Sort
    queue<int> zeroin;
    int current = 0;
    int count = 0;

    // Calculate Indegrees
    vector<int> indegree(size);
    for(auto i : adj) {
        for(auto j : i) {
            indegree[j]++;
        }
    }

    // Add players to queue
    for(int i = 0; i < size; i++) {
        if(indegree[i] == 0) {
            zeroin.push(i);
        }
    }

    // Run the Topo Sort
    while(!zeroin.empty()) {
        /*
        if(zeroin.size() > 1) {
            cout << "inconsistent" << endl;
            return 0;
        }
        */

        current = zeroin.front();
        zeroin.pop();

        for(auto j : adj[current]) {
            indegree[j]--;
            if(indegree[j] == 0) {
                zeroin.push(j);
            }
        }

        count++;
    }

    // Get the results
    if(count != size) {
        cout << "inconsistent" << endl;
        return 0;
    }
    else {
        cout << "consistent" << endl;
        return 0;
    }
}
