#include <bits/stdc++.h>
using namespace std;

vector<int> p(1000001,-1);//change size here if needed
int find(int x) {return p[x] < 0 ? x : p[x] = find(p[x]);}
void merge(int x, int y) {
    if((x=find(x)) == (y=find(y))) return;
    if(p[y] < p[x]) swap(x,y);
    p[x] += p[y];
    p[y] = x;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> animal(n);
    unordered_map<string, vector<string>> adj;
    unordered_map<string, int> deg;//in-out
    unordered_map<string, int> toID;
    int found = 0;
    for(int i = 0; i < n; ++i) {
        cin >> animal[i];
        toID[animal[i]] = i;
        int size;
        cin >> size;
        for(int j = 0; j < size; ++j) {
            string to;
            cin >> to;
            if(to == animal[i]) continue;
            ++found;
            adj[animal[i]].push_back(to);
            ++deg[to];
            --deg[animal[i]];
        }
    }
    if(found == 0) {
        cout << "FALSE ALARM\n";
        return 0;
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < adj[animal[i]].size(); ++j) {
            string to = adj[animal[i]][j];
            int u = toID[to];
            int v = toID[animal[i]];
            merge(u,v);
        }
    }
    int CC = 0;
    for(int i = 0; i < n; ++i) {
        if(-p[i] == 1) continue;
        if(p[i] < 0)
            ++CC;
    }
    if(CC > 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    string start = "";
    int ones = 0, negOnes = 0;
    for(int i = 0; i < n; ++i) {
        if(deg[animal[i]] > 1) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        if(deg[animal[i]] < -1) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        if(deg[animal[i]] == 1) {
            ++ones;
        }
        if(deg[animal[i]] == -1) {
            ++negOnes;
        }
    }
    if(ones == 1 && negOnes == 1) {
        cout << "POSSIBLE\n";
        return 0;
    }
    if(ones == 0 && negOnes == 0) {
        cout << "POSSIBLE\n";
        return 0;
    }
    cout << "IMPOSSIBLE\n";
}
