#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 60;

int main() {
    int n;
    cin >> n;

    vector<ll> cost(n);
    for(auto& i : cost) {
        cin >> i;
    }

    vector<vector<ll>> dist;
    dist.resize(n, vector<ll>(n+1, inf));

    priority_queue<pair<ll, pair<int,int>>> q;
    q.push({0, {1,1}});
    dist[0][0] = 0;
    dist[1][1] = cost[1];

    while(!q.empty()) {
        int curr = q.top().second.first;
        int time = q.top().second.second;
        q.pop();

        if(curr == n-1) {
            cout << dist[curr][time] << endl;
            break;
        }

        int next = curr - time;
        if(next >= 0) {
            if(dist[next][time] == inf) {
                dist[next][time] = dist[curr][time] + cost[next];
                q.push({-dist[next][time], {next, time}});
            }
        }

        next = curr + time + 1;
        if(next < n) {
            if(dist[next][time+1] == inf) {
                dist[next][time+1] = dist[curr][time] + cost[next];
                q.push({-dist[next][time+1], {next, time+1}});
            }
        }
    }
}
