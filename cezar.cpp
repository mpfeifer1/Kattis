#include <bits/stdc++.h>

using namespace std;

// Takes in two strings, adds an edge if possible
// returns whether or not it is possible using this config
bool cmp(vector<vector<bool>>& adj, vector<int>& deg, string s1, string s2) {
    for(int i = 0; i < min(s1.size(), s2.size()); i++) {
        if(s1[i] != s2[i]) {
            if(!adj[s1[i]-'a'][s2[i]-'a']) {
                adj[s1[i]-'a'][s2[i]-'a'] = true;
                deg[s2[i]-'a']++;
            }
            return true;
        }
    }

    return s1.size() < s2.size();
}

// From the toposort order, build the answer
string convert(string s) {
    string ans(26, 'a');

    for(int i = 0; i < s.size(); i++) {
        ans[s[i]-'a'] = i+'a';
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<string> input(n);
    for(auto& i : input) {
        cin >> i;
    }

    vector<string> sorted(n);
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        t--;
        sorted[i] = input[t];
    }

    vector<int> deg(26, 0);
    vector<vector<bool>> adj;
    adj.resize(26, vector<bool>(26, false));

    // For each pair, do a string compare, and add edge or detect
    // if impossible
    bool works = true;
    for(int i = 1; i < n; i++) {
        works &= cmp(adj, deg, sorted[i-1], sorted[i]);
    }

    // Prepare toposort
    queue<int> q;
    for(int i = 0; i < 26; i++) {
        if(deg[i] == 0) {
            q.push(i);
        }
    }
    string order = "";

    // Run toposort
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        order.push_back('a'+curr);

        for(int i = 0; i < 26; i++) {
            if(adj[curr][i]) {
                deg[i]--;
                if(deg[i] == 0) {
                    q.push(i);
                }
            }
        }
    }

    // Print answer
    if(works && order.size() == 26) {
        cout << "DA" << endl;
        order = convert(order);
        cout << order << endl;
    }
    else {
        cout << "NE" << endl;
    }

}
