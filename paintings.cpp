#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int ways = 0;
vector<int> best;
vector<bool> used;
vector<int> here;
vector<vector<bool>> good;

void recurse() {
    if(here.size() == n) {
        if(best.size() == 0) {
            for(auto i : here) {
                best.push_back(i);
            }
        }
        ways++;
        return;
    }
    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            if(here.size() > 0 && !good[here.back()][i]) {
                continue;
            }

            used[i] = true;
            here.push_back(i);

            recurse();

            here.pop_back();
            used[i] = false;
        }
    }
}

void solve() {
    cin >> n;

    used.clear();
    used.resize(n,false);

    map<string,int> color;
    vector<string> colors;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        color[s] = i;
        colors.push_back(s);
    }

    good.clear();
    good.resize(n,vector<bool>(n,true));
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        int n1 = color[s1];
        int n2 = color[s2];
        good[n1][n2] = false;
        good[n2][n1] = false;
    }

    recurse();

    cout << ways << endl;
    for(auto i : best) {
        cout << colors[i] << " ";
    }
    cout << endl;

    ways = 0;
    best.clear();
}

int main() {
    int cases;
    cin >> cases;

    while(cases--) {
        solve();
    }
}
