#include <bits/stdc++.h>

using namespace std;

vector<int> split(string s) {
    vector<string> temp = {""};
    for(auto i : s) {
        if(i == ' ') {
            temp.push_back("");
        }
        else {
            temp.back().push_back(i);
        }
    }

    vector<int> ret;
    for(auto i : temp) {
        ret.push_back(stoi(i));
    }

    return ret;
}

int main() {
    int n;
    cin >> n;

    vector<vector<bool>> adj;
    adj.resize(n, vector<bool>(n, false));

    cin.ignore();
    for(int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        for(auto j : split(s)) {
            adj[i][j] = true;
        }
    }

    int best = 2;
    for(int mask = 0; mask < (1<<n); mask++) {
        vector<int> subset;
        for(int i = 0; i < n; i++) {
            if(mask & (1<<i)) {
                subset.push_back(i);
            }
        }

        if(subset.size() <= best) {
            continue;
        }

        bool clique = true;
        for(int i = 0; i < subset.size(); i++) {
            for(int j = i+1; j < subset.size(); j++) {
                if(!adj[subset[i]][subset[j]]) {
                    clique = false;
                    break;
                }
            }
            if(!clique) break;
        }

        if(clique) {
            best = max(best, (int)subset.size());
        }
    }

    cout << best << endl;
}
