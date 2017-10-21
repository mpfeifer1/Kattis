#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

pair<ll, ll> simulate(vector<bool> path) {
    ll l = 1;
    ll r = 1;

    for(auto i : path) {
        if(i) {
            l = l+r;
        }
        else {
            r = l+r;
        }
    }

    pair<ll, ll> p = {l, r};
    return p;
}

int main() {
    int cases;
    cin >> cases;

    for(int i = 0; i < cases; i++) {
        ll garbo, query;
        cin >> garbo >> query;
        cout << garbo << " ";

        vector<bool> path;
        while(query > 1) {
            path.push_back(query % 2);
            query /= 2;
        }

        reverse(path.begin(), path.end());

        pair<ll, ll> p = simulate(path);
        cout << p.first << "/" << p.second << endl;
    }
}
