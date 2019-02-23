#include <bits/stdc++.h>

using namespace std;

// Returns an array with the indexes of the LIS
template <class T>
vector<int> LIS(vector<T>& v) {
    vector<int> p(v.size(), -1);
    vector<int> t(v.size(), 0);

    int lis = 1;
    for(int i = 1; i < v.size(); i++) {
        if(v[i] <= v[t[0]]) {
            t[0] = i;
        }
        else if(v[i] > v[t[lis - 1]]) {
            p[i] = t[lis - 1];
            t[lis++] = i;
        }
        else {
            int l = -1;
            int r = lis - 1;
            while(r - l > 1) {
                int m = l + (r - l) / 2;
                if(v[t[m]] >= v[i]) r = m;
                else l = m;
            }
            p[i] = t[r - 1];
            t[r] = i;
        }
    }

    vector<int> ans;
    for(int i = t[lis - 1]; i >= 0; i = p[i]) {
        ans.push_back(i);
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> deg(n,0);

    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;
        adj[n2].push_back(n1);
        deg[n1]++;
    }

    set<int> zeroin;
    for(int i = 0; i < n; i++) {
        if(deg[i] == 0) {
            zeroin.insert(i);
        }
    }

    // Use toposort to build the permutation graph
    vector<int> permutation;
    while(!zeroin.empty()) {
        int curr = *zeroin.begin();
        zeroin.erase(zeroin.begin());

        permutation.push_back(curr);

        for(auto next : adj[curr]) {
            deg[next]--;
            if(deg[next] == 0) {
                zeroin.insert(next);
            }
        }
    }

    for(auto& i : permutation) {
        i *= -1;
    }

    cout << LIS(permutation).size() << endl;
}
