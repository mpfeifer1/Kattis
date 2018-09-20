#include <bits/stdc++.h>

using namespace std;

// Calculate distance between two points
int d(pair<int,int>& p1, pair<int,int>& p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

// Sort strings by their value, then alphabetically
bool cmp(pair<string,int>& p1, pair<string,int>& p2) {
    if(p1 == p2) return false;
    if(p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

int main() {
    // Build the keyboard
    vector<string> v;
    v.push_back("qwertyuiop");
    v.push_back("asdfghjkl");
    v.push_back("zxcvbnm");

    // Map character to its position
    map<char,pair<int,int>> pos;
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            pos[v[i][j]] = {i,j};
        }
    }

    // For each case
    int cases;
    cin >> cases;
    while(cases--) {
        // Read in input
        string s;
        cin >> s;
        int n;
        cin >> n;

        // Map strings to their differences
        vector<pair<string,int>> m;

        // For each query string
        for(int i = 0; i < n; i++) {
            // Read it in
            string t;
            cin >> t;

            // For each character, calculate the difference
            int diff = 0;
            for(int j = 0; j < t.size(); j++) {
                pair<int,int> p1 = pos[s[j]];
                pair<int,int> p2 = pos[t[j]];
                diff += d(p1,p2);
            }

            // Save this string+difference
            m.push_back({t,diff});
        }

        // Sort the strings by difference
        sort(m.begin(), m.end(), cmp);

        // Print all the strings
        for(auto i : m) {
            cout << i.first << " " << i.second << endl;
        }
    }

}
