#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    map<int,int> pairs;
    stack<int> idx;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            idx.push(i);
        }
        if(s[i] == ')') {
            pairs[idx.top()] = i;
            idx.pop();
        }
    }

    vector<string> ans;

    vector<pair<int,int>> pairs2;
    for(auto i : pairs) {
        pairs2.push_back(i);
    }

    int m = 1 << pairs.size();
    for(int i = 1; i < m; i++) {
        vector<bool> print(s.size(), true);

        for(int j = 0; j < pairs.size(); j++) {
            if(i & (1<<j)) {
                print[pairs2[j].first] = false;
                print[pairs2[j].second] = false;
            }
        }

        string t = "";
        for(int j = 0; j < s.size(); j++) {
            if(print[j]) {
                t += s[j];
            }
        }
        ans.push_back(t);
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for(auto i : ans) {
        cout << i << endl;
    }
}


