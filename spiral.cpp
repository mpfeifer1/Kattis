#include <bits/stdc++.h>

using namespace std;
int inf = 1 << 30;

vector<int> dx = {1,-1,0,0};
vector<int> dy = {0,0,1,-1};

bool prime(int n) {
    if(n <= 2) return true;
    if(n % 2 == 0) return false;
    for(int i = 3; i <= sqrt(n); i += 2) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int currx = 0;
    int curry = 0;

    map<pair<int,int>,int> to_num;
    vector<pair<int,int>> to_coord(10001,{inf,inf});

    to_num[{currx,curry}] = 1;
    to_coord[1] = {currx,curry};

    int curr = 2;
    int steps = 1;
    while(curr <= 10000) {
        for(int i = 0; i < 4 && curr <= 10000; i++) {
            for(int j = 0; j < steps && curr <= 10000; j++) {
                if(i == 0) {
                    curry--;
                }
                if(i == 1) {
                    currx--;
                }
                if(i == 2) { curry++;
                }
                if(i == 3) {
                    currx++;
                }

                if(!prime(curr)) {
                    to_num[{currx,curry}] = curr;
                    to_coord[curr] = {currx,curry};
                }

                curr++;
            }
            if(i % 2 == 1) {
                steps++;
            }
        }
    }

    /*
    for(int i = -4; i <= 4; i++) {
        for(int j = -4; j <= 4; j++) {
            cout << to_num[{i,j}] << "\t";
        }
        cout << endl;
    }
    */

    int num = 1;
    int n1, n2;
    while(cin >> n1 >> n2) {
        cout << "Case " << num++ << ": ";

        map<pair<int,int>,int> vis;
        queue<pair<int,int>> q;
        q.push(to_coord[n1]);

        while(!q.empty()) {
            pair<int,int> curr = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nextx = curr.first + dx[i];
                int nexty = curr.second + dy[i];
                if(!to_num.count({nextx,nexty})) {
                    continue;
                }
                if(vis.count({nextx,nexty})) {
                    continue;
                }
                vis[{nextx,nexty}] = vis[curr] + 1;
                q.push({nextx,nexty});
            }
        }

        if(vis[to_coord[n2]] == 0 && n1 != n2) {
            cout << "impossible" << endl;
        }
        else {
            cout << vis[to_coord[n2]] << endl;
        }
    }
}
