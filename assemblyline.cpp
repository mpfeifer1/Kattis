#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 60;

pair<int, char> table[26][26];
string s;
int k;
vector<int> memo[200][200];
int toPos[256];

void solve(int L, int R) {
    if(L > R) return;
    if(L == R) {
        memo[L][R].resize(k, 1e9);
        memo[L][R][toPos[s[L]]] = 0;
        return;    
    }
    if(memo[L][R].size()) {
        return;
    }
    memo[L][R].resize(k, 1e9);
    for(int split = L; split < R; ++split) {
        solve(L, split);
        solve(split+1, R);
        for(int let1 = 0; let1 < k; ++let1) {
            for(int let2 = 0; let2 < k; ++let2) {
                int newCost = memo[L][split][let1];
                newCost += memo[split+1][R][let2];
                newCost += table[let1][let2].first;
                
                int newLetter = toPos[table[let1][let2].second];
                
                if(memo[L][R][newLetter] > newCost) {
                    memo[L][R][newLetter] = newCost;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> k;
    vector<char> symbols(k);
    for(int i = 0; i < k; ++i) {
        cin >> symbols[i];
        toPos[symbols[i]] = i;
    }
    for(int i = 0; i < k; ++i) {
        for(int j = 0; j < k; ++j) {
            int cost;
            char dash;
            char result;
            cin >> cost >> dash >> result;
            table[i][j] = {cost, result};
        }
    }
    int q;
    cin >> q;
    while(q--) {
        cin >> s;
        for(int i = 0; i < s.size(); ++i) {
            for(int j = i; j < s.size(); ++j) {
                memo[i][j].clear();
            }
        }
        pair<int, char> res = {1e9, '$'};
        solve(0,(int)s.size()-1);
        for(int i = 0; i < k; ++i) {
            if(memo[0][(int)s.size()-1][i] < res.first) {
                res.first = memo[0][(int)s.size()-1][i];
                res.second = symbols[i];
            }
        }
        cout << res.first << '-' << res.second << '\n';
    }
}
