#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct country {
    bool left;
    int incoming;
    int neighborsleft;
    vector<int> neighbors;
};

int main() {
    int c, p, x, l;
    cin >> c >> p >> x >> l;

    vector<country> v;
    for(int i = 0; i < c+1; i++) {
        country c;
        c.left = false;
        c.incoming = 0;
        c.neighborsleft = 0;
        v.push_back(c);
    }

    for(int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;

        v[a].incoming++;
        v[a].neighborsleft++;
        v[a].neighbors.push_back(b);

        v[b].incoming++;
        v[b].neighborsleft++;
        v[b].neighbors.push_back(a);
    }

    queue<int> toprocess;

    v[l].left = true;
    for(auto i : v[l].neighbors) {
        v[i].neighborsleft--;
        toprocess.push(i);
    }

    while(toprocess.size() > 0) {
        int c = toprocess.front();
        toprocess.pop();

        if(v[c].left) {
            continue;
        }

        if(v[c].neighborsleft <= v[c].incoming / 2) {
            v[c].left = true;
            for(auto i : v[c].neighbors) {
                v[i].neighborsleft--;
                toprocess.push(i);
            }
        }
    }

    if(v[x].left) {
        cout << "leave" << endl;
    }
    else {
        cout << "stay" << endl;
    }
}
