#include <bits/stdc++.h>

using namespace std;

void dfs1(unordered_map<string, pair<int, vector<string>>>& m, unordered_set<string>& vis, stack<string>& r, string curr) {
    if(vis.count(curr) > 0) {
        return;
    }
    vis.insert(curr);

    for(auto next : m[curr].second) {
        dfs1(m, vis, r, next);
    }

    r.push(curr);
}

void dfs2(unordered_map<string, pair<int, vector<string>>>& m, unordered_set<string>& vis, vector<string>& comp, string curr) {
    if(vis.count(curr) > 0) {
        return;
    }
    vis.insert(curr);
    comp.push_back(curr);

    for(auto next : m[curr].second) {
        dfs2(m, vis, comp, next);
    }
}

int main() {
    int n;
    cin >> n;

    unordered_map<string, pair<int, vector<string>>> m1;
    unordered_map<string, pair<int, vector<string>>> m2;
    unordered_set<string> names;

    for(int i = 0; i < n; i++) {
        string name, lang, s;
        cin >> name >> lang;

        names.insert(lang);

        m1[lang].first++;
        m2[lang].first++;

        while(cin.peek() != '\n') {
            cin >> s;
            m1[lang].second.push_back(s);
            m2[s].second.push_back(lang);
        }
    }

    stack<string> r;
    unordered_set<string> vis;
    for(auto i : names) {
        if(vis.count(i) > 0) {
            continue;
        }

        dfs1(m1, vis, r, i);
    }

    vis.clear();
    int best = 0;
    while(!r.empty()) {
        string curr = r.top();
        r.pop();

        if(vis.count(curr) > 0) {
            continue;
        }

        vector<string> comp;
        dfs2(m2, vis, comp, curr);

        int here = 0;
        for(auto i : comp) {
            here += m1[i].first;
        }

        best = max(here, best);
    }

    cout << n - best << endl;
}
