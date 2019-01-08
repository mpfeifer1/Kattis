#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// Their coords are given in the form {down x, right y}

vector<int> dx = {0,0,1,-1};
vector<int> dy = {1,-1,0,0};
vector<int> d = {'<','>','^','v'};

int main() {
    int n, m, b;
    cin >> n >> m >> b;

    map<pair<int,int>, int> conv;

    vector<pair<int,int>> coords(b);
    vector<char> dir(b,'?');

    for(int i = 0; i < b; i++) {
        pair<int,int> p;
        cin >> p.first >> p.second;
        conv[p] = i;
        coords[i] = p;
    }

    // {a,b} means 'a' must be placed before 'b'
    set<pair<int,int>> edges;
    vector<int> par(b,-1);

    // BFS out from here to figure out what dir each block has
    // additionally, make an edge for each 'move'
    queue<int> q;
    q.push(0);
    dir[0] = '.';

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        if(par[curr] != -1) {
            edges.insert({par[curr],curr});
        }

        int x = coords[curr].first;
        int y = coords[curr].second;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(conv.count({nx,ny})) {
                int next = conv[{nx,ny}];
                if(dir[next] != '?') continue;

                par[next] = curr;
                dir[next] = d[i];
                q.push(next);
            }
        }
    }

    // Debugging - print out all tiles' directions
    /*
    for(int i = 0; i < b; i++) {
        cout << coords[i].first << " " << coords[i].second << " " << dir[i] << endl;
    }
    */

    // For each row and col, make sure we have all
    // necessary edges added
    map<int,set<int>> rows;
    map<int,set<int>> cols;

    for(auto i : coords) {
        rows[i.first].insert(i.second);
        cols[i.second].insert(i.first);
    }

    // For each block, depending on his direction, find the
    // next largest or smallest value, add an edge
    for(int i = 0; i < b; i++) {
        int x = coords[i].first;
        int y = coords[i].second;

        bool works = false;

        // Look for larger 'Y'
        if(dir[i] == '<') {
            auto it = rows[x].find(y);
            it++;
            if(it != rows[x].end()) {
                works = true;
                y = *it;
            }
        }

        // Look for smaller 'Y'
        if(dir[i] == '>') {
            auto it = rows[x].find(y);
            if(it != rows[x].begin()) {
                works = true;
                it--;
                y = *it;
            }
        }

        // Look for larger 'X'
        if(dir[i] == '^') {
            auto it = cols[y].find(x);
            it++;
            if(it != cols[y].end()) {
                works = true;
                x = *it;
            }
        }

        // Look for smaller 'X'
        if(dir[i] == 'v') {
            auto it = cols[y].find(x);
            if(it != cols[y].begin()) {
                works = true;
                it--;
                x = *it;
            }
        }

        // Add the edge from x,y to coods[i].first,second
        if(works) {
            if(!conv.count({x,y})) cout << "FUCK" << endl;
            edges.insert({i, conv[{x,y}]});
        }
    }

    // From all the edges, build a toposort graph
    // If cycle, impossible, else just store and print
    // the moves in order

    vector<vector<int>> adj(b);
    vector<int> deg(b,0);
    for(auto i : edges) {
        adj[i.first].push_back(i.second);
        deg[i.second]++;
    }

    queue<int> zeroin;
    for(int i = 0; i < b; i++) {
        if(deg[i] == 0) {
            zeroin.push(i);
        }
    }

    int processed = 0;
    vector<pair<char,int>> moves;
    while(!zeroin.empty()) {
        int curr = zeroin.front();
        zeroin.pop();
        processed++;

        if(dir[curr] == '<' || dir[curr] == '>') {
            moves.push_back({dir[curr],coords[curr].first});
        }
        if(dir[curr] == '^' || dir[curr] == 'v') {
            moves.push_back({dir[curr],coords[curr].second});
        }

        for(auto next : adj[curr]) {
            deg[next]--;
            if(deg[next] == 0) {
                zeroin.push(next);
            }
        }
    }

    if(processed == b) {
        cout << "possible" << endl;
        for(auto i : moves) {
            cout << i.first << " " << i.second << '\n';
        }
    }
    else {
        cout << "impossible" << endl;
    }
}
