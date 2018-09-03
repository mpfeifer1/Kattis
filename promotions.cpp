#include <bits/stdc++.h>

using namespace std;

void getleastabove(queue<int> zeroin, vector<int> deg, vector<int>& leastabove, vector<vector<int>>& chi, vector<vector<int>>& par, int skip, int e) {
    vector<int> vis(e, false);
    queue<int> q;
    q.push(skip);
    vis[skip] = true;

    int above = 0;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(auto next : par[curr]) {
            if(!vis[next]) {
                above++;
                vis[next] = true;
                q.push(next);
            }
        }
    }

    leastabove[skip] = above;
}

void getmostabove(queue<int> zeroin, vector<int> deg, vector<int>& mostabove, vector<vector<int>>& chi, vector<vector<int>>& par, int skip, int e) {
    int processed = 0;
    while(!zeroin.empty()) {
        int curr = zeroin.front();
        zeroin.pop();
        if(curr == skip) {
            continue;
        }
        processed++;

        // Process children
        for(auto next : chi[curr]) {
            deg[next]--;
            if(deg[next] == 0) {
                zeroin.push(next);
            }
        }
    }

    mostabove[skip] = processed;
}

int main() {
    int a, b, p, e;
    cin >> a >> b >> e >> p;

    vector<vector<int>> chi(e);
    vector<vector<int>> par(e);
    vector<int> deg(e, 0);
    vector<int> leastabove(e, 0);
    vector<int> mostabove(e, 0);

    for(int i = 0; i < p; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        chi[n1].push_back(n2);
        par[n2].push_back(n1);

        deg[n2]++;
    }

    queue<int> zeroin;
    for(int i = 0; i < e; i++) {
        if(deg[i] == 0) {
            zeroin.push(i);
        }
    }

    for(int i = 0; i < e; i++) {
        getleastabove(zeroin, deg, leastabove, chi, par, i, e);
        getmostabove(zeroin, deg, mostabove, chi, par, i, e);
    }

    int guaranteed1 = 0;
    int guaranteed2 = 0;
    int impossible = 0;
    for(int i = 0; i < e; i++) {
        if(mostabove[i] < a) {
            guaranteed1++;
        }
        if(mostabove[i] < b) {
            guaranteed2++;
        }
        if(leastabove[i] >= b) {
            impossible++;
        }
    }

    cout << guaranteed1 << endl;
    cout << guaranteed2 << endl;
    cout << impossible << endl;
}
