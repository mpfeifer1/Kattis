#include <bits/stdc++.h>

using namespace std;
int inf = 1 << 30;

struct state {
    int dist;
    int subset;
    int node;
};

bool operator<(const state& s1, const state& s2) {
    if(s1.dist == s2.dist) {
        if(s1.subset == s2.subset) {
            return s1.node < s2.node;
        }
        return s1.subset < s2.subset;
    }
    return s1.dist < s2.dist;
}

int getdist(pair<int,int> p1, pair<int,int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> locs(n);
    vector<int> mon_bits(n);

    map<string,int> conv;
    int shift = 0;

    for(int i = 0; i < n; i++) {
        int x, y;
        string s;
        cin >> x >> y >> s;
        locs[i] = {x,y};
        if(!conv.count(s)) {
            conv[s] = 1 << shift;
            shift++;
        }
        mon_bits[i] = conv[s];
    }
    locs.push_back({0,0});
    mon_bits.push_back(0);

    vector<vector<int>> pairdist(n+1,vector<int>(n+1));
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            pairdist[i][j] = getdist(locs[i],locs[j]);
        }
    }

    vector<vector<int>> dist;
    dist.resize((1 << shift), vector<int>(n+1, inf));

    dist[0][n] = 0;
    set<state> s;
    s.insert({0,0,n});

    while(!s.empty()) {
        int currn = s.begin()->node;
        int currs = s.begin()->subset;
        s.erase(s.begin());

        for(int i = 0; i <= n; i++) {
            int nextn = i;
            int nexts = currs | mon_bits[i];
            int weight = pairdist[currn][nextn];

            if(dist[nexts][nextn] > dist[currs][currn] + weight) {
                s.erase({dist[nexts][nextn], nexts, nextn});
                dist[nexts][nextn] = dist[currs][currn] + weight;
                s.insert({dist[nexts][nextn], nexts, nextn});
            }
        }
    }

    cout << dist[(1<<shift)-1][n] << endl;
}
