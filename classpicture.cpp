#include <bits/stdc++.h>

using namespace std;

bool works(vector<int>& perm, vector<vector<bool>>& edges) {
    for(int i = 1; i < perm.size(); i++) {
        if(edges[perm[i-1]][perm[i]]) {
            return false;
        }
    }
    return true;
}

void print(vector<int>& v, vector<string>& s) {
    for(auto i : v) {
        cout << s[i] << " ";
    }
    cout << endl;
}

void solve(int n) {
    vector<string> v;
    map<string,int> conv;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }


    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        conv[v[i]] = i;
    }

    vector<vector<bool>> edges;
    edges.resize(n, vector<bool>(n, false));

    int m;
    cin >> m;
    while(m--) {
        string s1, s2;
        cin >> s1 >> s2;
        int n1 = conv[s1];
        int n2 = conv[s2];
        edges[n1][n2] = true;
        edges[n2][n1] = true;
    }

    vector<int> perm;
    for(int i = 0; i < n; i++) {
        perm.push_back(i);
    }

    do {
        if(works(perm, edges)) {
            print(perm, v);
            return;
        }
    } while(next_permutation(perm.begin(), perm.end()));

    cout << "You all need therapy." << endl;
}

int main() {
    int n;
    while(cin >> n) {
        solve(n);
    }
}
