#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

ll inf = (ll(1) << 62);

int main() {
    ll floors;
    cin >> floors;
    ll start, goal;
    cin >> start >> goal;
    start--;
    goal--;
    ll up, down;
    cin >> up >> down;

    vector<ll> visited(floors, inf);

    visited[start] = 0;
    queue<ll> q;
    q.push(start);
    while(!q.empty()) {
        ll here = q.front();
        q.pop();

        if(here+up < floors && visited[here] + 1 < visited[here+up]) {
            visited[here+up] = visited[here]+1;
            q.push(here+up);
        }
        if(here-down >= 0 && visited[here] + 1 < visited[here-down]) {
            visited[here-down] = visited[here]+1;
            q.push(here-down);
        }
    }

    if(visited[goal] == inf) {
        cout << "use the stairs" << endl;
        return 0;
    }
    cout << visited[goal] << endl;
}
