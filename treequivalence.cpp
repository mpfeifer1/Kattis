#include <bits/stdc++.h>

using namespace std;
typedef vector<vector<int>> adjlist;

pair<adjlist,vector<char>> tree(string s) {
    // Find all nodes in tree
    vector<char> letter;
    for(auto& i : s) {
        if(isalpha(i)) letter.push_back(i);
    }
    int n = letter.size();

    // Build the tree
    adjlist adj(n);
    stack<int> st;
    int curr = 0;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == '(') {
            st.push(curr);
        }
        if(s[i] == ')') {
            st.pop();
        }
        if(isalpha(s[i])) {
            curr++;
            adj[st.top()].push_back(curr);
        }
    }

    // Return tree and mapping
    return {adj, letter};
}

vector<pair<int,int>> ans;

vector<int> deg;
vector<int> rem;
vector<int> sub;

void buildhelper(adjlist& adj, int curr = 0) {
    // If base case add itself with dist of tree len
    if(adj[curr].size() == 0) {
        ans.push_back({curr, rem[curr]});
        return;
    }

    // For each child, Add itself + size of subtree,
    for(auto next : adj[curr]) {
        ans.push_back({curr, sub[next]});
        rem[curr] -= sub[next];
        buildhelper(adj, next);
    }

    // Add itself one last time
    if(curr != 0) {
        ans.push_back({curr, rem[curr]});
    }
}

void getdegree(adjlist& adj, int curr = 0) {
    sub[curr] = 2;
    for(auto next : adj[curr]) {
        getdegree(adj, next);
        sub[curr] += sub[next];
    }
}

vector<pair<char,int>> build(string& s) {
    // Turn the string into an adj list, get a map of idx to letter
    pair<adjlist, vector<char>> p = tree(s);

    // Extract info
    adjlist adj = p.first;
    vector<char> letter = p.second;
    int n = letter.size();

    // Reset globals
    ans.clear();
    deg.clear();
    deg.resize(n, 0);
    rem.clear();
    rem.resize(n, 0);
    sub.clear();
    sub.resize(n,0);

    // Turn adj into degrees
    for(int i = 0; i < n; i++) {
        for(auto j : adj[i]) {
            deg[i]++;
            deg[j]++;
        }
    }

    // Count total 'size' of tree
    int size = 0;
    for(auto i : deg) {
        size += i;
    }

    // Count degrees in each subtree
    getdegree(adj);

    // Let all nodes' remaining be equal to size
    for(int i = 0; i < n; i++) {
        rem[i] = size;
    }

    // Make the string
    buildhelper(adj);

    // Convert the list to use actual letters instead of indexes
    vector<pair<char,int>> v;
    for(auto i : ans) {
        v.push_back({letter[i.first], i.second});
    }

    // Return the answer
    return v;
}

string print(vector<pair<char,int>>& v) {
    string s;
    for(auto i : v) {
        s += i.first;
        s += ",";
        s += i.second;
        s += " ";
    }
    return s;
}

bool solve() {
    string s, t;
    cin >> s >> t;

    vector<pair<char,int>> s1, t1;
    s1 = build(s);
    t1 = build(t);

    string pattern = print(s1);
    string text = print(t1);
    text += text;

    return text.find(pattern) != string::npos;
}

int main() {
    int cases;
    cin >> cases;

    while(cases--) {
        if(solve()) {
            cout << "same" << endl;
        }
        else {
            cout << "different" << endl;
        }
    }
}
