#include <bits/stdc++.h>

using namespace std;

struct group {
    vector<bool> used;
    vector<pair<int,int>> coords;
    int num;
};

bool cmp(const group& g1, const group& g2) {
    return g1.coords.size() < g2.coords.size();
}

int n, m;
vector<vector<char>> v;
vector<group> groups;

bool works(int x, int y) {
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            if(i == 0 && j == 0) continue;
            if(v[x+i][y+j] == v[x][y]) return false;
        }
    }
    return true;
}

void solve(int currGroup, int currSpot) {
    // Base case
    if(currGroup == groups.size()) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        exit(0);
    }

    // If we've stepped too far in current group, move to next
    if(groups[currGroup].coords.size() == currSpot) {
        solve(currGroup+1,0);
        return;
    }

    // For each number
    for(int j = 1; j <= groups[currGroup].num; j++) {
        // If we can place it, place it
        if(groups[currGroup].used[j]) continue;

        pair<int,int> coord = groups[currGroup].coords[currSpot];

        v[coord.first][coord.second] = j + '0';
        groups[currGroup].used[j] = true;

        if(works(coord.first,coord.second)) {
            solve(currGroup, currSpot+1);
        }

        groups[currGroup].used[j] = false;
        v[coord.first][coord.second] = '-';
    }
}

int main() {
    cin >> n >> m;

    v.resize(n+2,vector<char>(m+2,'-'));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }

    int segments;
    cin >> segments;

    groups.resize(segments);

    for(int i = 0; i < segments; i++) {
        groups[i].used.resize(8,false);
        int t;
        cin >> t;
        groups[i].num = t;
        for(int j = 0; j < t; j++) {
            int x, y;
            cin.ignore();
            cin.ignore();
            cin >> x;
            cin.ignore();
            cin >> y;
            cin.ignore();

            if(v[x][y] == '-') {
                groups[i].coords.push_back({x,y});
            }
            else {
                groups[i].used[v[x][y]-'0'] = true;
            }
        }
    }

    sort(groups.begin(),groups.end(),cmp);

    solve(0,0);
}
