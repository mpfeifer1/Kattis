#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int cases;
    cin >> cases;

    while(cases--) {
        int n;
        cin >> n;

        unordered_map<string, vector<unordered_set<string>>> m;
        vector<pair<unordered_set<string>,unordered_set<string>>> pizzas;

        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;

            int s1,s2;
            cin >> s1;
            vector<string> v(s1);
            unordered_set<string> top;
            for(auto& i : v) {
                cin >> i;
                top.insert(i);
            }

            cin >> s2;
            unordered_set<string> w;
            for(int i = 0; i < s2; i++) {
                string temp;
                cin >> temp;
                w.insert(temp);
            }

            for(auto i : v) {
                m[i].push_back(w);
            }

            pizzas.push_back({top, w});
        }

        set<pair<string,string>> s;

        // For each ingredient
        for(auto i : m) {
            // For all of its sets
            unordered_set<string> all = i.second[0];

            for(auto j : i.second) {
                unordered_set<string> next;
                // For everything in set, make sure it's in both
                for(auto k : j) {
                    if(all.count(k) > 0) {
                        next.insert(k);
                    }
                }
                all.clear();
                all = next;
            }

            for(auto j : all) {
                s.insert({i.first, j});
            }
        }

        for(auto i : s) {
            bool works = true;

            for(auto j : pizzas) {
                if(j.first.count(i.first) != j.second.count(i.second)) {
                    works = false;
                }
            }

            if(works) {
                cout << "(" << i.first << ", " << i.second << ")" << endl;
            }
        }
        cout << endl;
    }
}
