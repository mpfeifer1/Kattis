#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

ld inf = (ld)10000000;

ld getdist(pair<ld,ld>& p1, pair<ld,ld>& p2) {
    ld d1 = pow(p1.first - p2.first, 2);
    ld d2 = pow(p1.second - p2.second, 2);
    return sqrt(d1 + d2);
}

void solve(int n) {
    vector<pair<ld,ld>> points;

    // Read in start points
    ld sx,sy;
    cin >> sx >> sy;
    points.push_back({sx,sy});

    // Read in central gates
    for(int i = 0; i < n-1; i++) {
        ld y, x1, x2;
        cin >> y >> x1 >> x2;
        points.push_back({x1,y});
        points.push_back({x2,y});
    }

    // Read in end gate
    ld ey, ex1, ex2;
    cin >> ey >> ex1 >> ex2;

    // Find all X values
    vector<ld> x_vals;
    x_vals.push_back(sx);
    x_vals.push_back(ex1);
    x_vals.push_back(ex2);
    for(auto& i : points) {
        x_vals.push_back(i.first);
    }
    // Sort them, keep unique points
    sort(x_vals.begin(),x_vals.end());
    x_vals.erase(unique(x_vals.begin(),x_vals.end()),x_vals.end());

    // Build endpoint for each X val
    for(auto& i : x_vals) {
        if(ex1 <= i && i <= ex2) {
            points.push_back({i,ey});
        }
    }

    // {dest,weight}
    vector<vector<pair<int,ld>>> adj(points.size());

    // Count all the real points
    int real = (n-1) * 2;

    // For each point that's not on the bottom
    for(int i = 0; i <= real; i++) {
        ld lo = -inf;
        ld hi = inf;

        ld x1 = points[i].first;
        ld y1 = points[i].second;

        // For each real point
        for(int j = (i%2==1)?i+2:i+1; j <= real; j++) {
            ld x2 = points[j].first;
            ld y2 = points[j].second;

            ld slope = (x2-x1)/(y2-y1);

            if(lo <= slope && slope <= hi) {
                ld dist = getdist(points[i],points[j]);
                adj[i].push_back({j,dist});
            }

            if(j % 2 == 1) {
                hi = min(hi,slope);
            }
            else {
                lo = max(lo,slope);
            }

            if(lo > hi) {
                break;
            }
        }

        // For each end point
        for(int j = real+1; j < points.size(); j++) {
            ld x2 = points[j].first;
            ld y2 = points[j].second;

            ld slope = (x2-x1)/(y2-y1);

            if(lo <= slope && slope <= hi) {
                ld dist = getdist(points[i],points[j]);
                adj[i].push_back({j,dist});
            }
        }
    }

    // Debugging - print adjacency list
    /*
    for(int i = 0; i < points.size(); i++) {
        cout << i << ": ";
        for(auto j : adj[i]) {
            cout << j.first << " ";// << j.second << "    ";
        }
        cout << endl;
    }
    cout << endl;
    */

    // Prepare toposort's
    vector<ld> dist(points.size(), inf);
    vector<int> deg(points.size(), 0);
    for(int i = 0; i < points.size(); i++) {
        for(auto& j : adj[i]) {
            deg[j.first]++;
        }
    }

    // Prepare queue
    queue<int> q;
    q.push(0);
    dist[0] = 0;

    // Run toposort
    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(auto& i : adj[curr]) {
            int next = i.first;
            ld weight = i.second;

            dist[next] = min(dist[next], dist[curr] + weight);

            deg[next]--;
            if(deg[next] == 0) {
                q.push(next);
            }
        }
    }


    /*
    for(int i = 0; i < points.size(); i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    */

    // Find answer
    ld best = inf;
    for(int i = real+1; i < points.size(); i++) {
        best = min(best,dist[i]);
    }

    cout << fixed;
    cout.precision(10);
    cout << best << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    while(cin >> n && n != 0) {
        solve(n);
    }
}
