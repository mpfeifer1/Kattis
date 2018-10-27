#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

queue<ll> q;
vector<bool> isleft;
vector<ll> l;
vector<ll> r;
vector<ll> deg;
vector<ll> balls;

void toposort(bool skiproot) {
    while(!q.empty()) {
        ll curr = q.front();
        q.pop();

        ll addfirst = (balls[curr]+1)/2;
        ll addsecond = (balls[curr])/2;

        if(isleft[curr]) {
            balls[l[curr]] += addfirst;
            balls[r[curr]] += addsecond;
        }
        else {
            balls[r[curr]] += addfirst;
            balls[l[curr]] += addsecond;
        }

        if(!(skiproot && l[curr] == 0)) {
            deg[l[curr]]--;
            if(deg[l[curr]] == 0) {
                q.push(l[curr]);
            }
        }
        if(!(skiproot && r[curr] == 0)) {
            deg[r[curr]]--;
            if(deg[r[curr]] == 0) {
                q.push(r[curr]);
            }
        }
    }
}

int main() {
    ll m, switches;
    cin >> m >> switches;

    isleft.resize(switches+1);
    l.resize(switches+1);
    r.resize(switches+1);
    deg.resize(switches+1,0);
    balls.resize(switches+1,0);

    for(ll i = 1; i <= switches; i++) {
        char c; cin >> c;
        if(c == 'L') isleft[i] = true;
        else isleft[i] = false;
        cin >> l[i] >> r[i];

        deg[l[i]]++;
        deg[r[i]]++;
    }
    deg[0] = (ll)1 << 60;

    for(int i = 2; i <= switches; i++) {
        if(deg[i] == 0) {
            q.push(i);
        }
    }
    toposort(true);

    q.push(1);
    balls[1] = m;
    toposort(false);

    for(ll i = 1; i <= switches; i++) {
        if(balls[i]%2 == 1) {
            isleft[i] = !isleft[i];
        }
        if(isleft[i]) {
            cout << "L";
        }
        else {
            cout << "R";
        }
    }
    cout << endl;
}
