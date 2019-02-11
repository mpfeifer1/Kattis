#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
ld inf = (ld)10000000000;

ll m, n;
ld r;

vector<int> dx = {1,-1,0,0};
vector<int> dy = {0,0,1,-1};

ld getdist(ll ax, ll ay, ll bx, ll by) {
    ld straight = (r / n);

    ld radius = ld(min(ay,by)) / n * r;
    ld circ = ld(2) * M_PI * radius;

    ld curved = (circ / 2) / m;

    ld ans = straight * abs(ay-by) + curved * abs(ax-bx);

    return ans;
}

int main() {
    ll ax,ay,bx,by;
    cin >> m >> n >> r;
    cin >> ax >> ay >> bx >> by;

    vector<vector<ld>> dist(m+1,vector<ld>(n+1,inf));

    set<pair<ld,pair<int,int>>> q;
    dist[ax][ay] = 0;
    q.insert({0,{ax,ay}});

    while(!q.empty()) {
        pair<int,int> curr = q.begin()->second;
        q.erase(q.begin());

        for(int i = 0; i < 4; i++) {
            pair<int,int> next = curr;
            next.first += dx[i];
            next.second += dy[i];

            if(next.first < 0) continue;
            if(next.second < 0) continue;
            if(next.first > m) continue;
            if(next.second > n) continue;

            ld weight = getdist(curr.first,curr.second,next.first,next.second);

            if(dist[next.first][next.second] > dist[curr.first][curr.second] + weight) {
                q.erase({dist[next.first][next.second],next});
                dist[next.first][next.second] = dist[curr.first][curr.second] + weight;
                q.insert({dist[next.first][next.second],next});
            }
        }
    }

    cout << fixed;
    cout.precision(8);
    cout << dist[bx][by] << endl;
}
