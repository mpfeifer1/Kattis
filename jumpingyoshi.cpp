#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<char,int> node;
typedef pair<node,char> state;

ll nodetoll(node& n) {
    return (ll(n.second)<<32) | n.first;
}

ll statetoll(state& s) {
    ll res = s.first.second;
    res <<= 16;
    res |= s.first.first;
    res <<= 16;
    res |= s.second;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    unordered_map<ll,vector<node>> adj;
    unordered_set<int> unreal;

    adj.reserve(6000000);
    unreal.reserve(6000000);

    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;

        node n1 = {'t',i};
        node n2 = {'l',i-t};
        node n3 = {'r',i+t};

        adj[nodetoll(n1)].push_back(n2);
        adj[nodetoll(n1)].push_back(n3);
        adj[nodetoll(n2)].push_back(n1);
        adj[nodetoll(n3)].push_back(n1);

        unreal.insert(i-t);
        unreal.insert(i+t);
    }

    for(auto& i : unreal) {
        node n1 = {'l',i};
        node n2 = {'r',i};

        adj[nodetoll(n1)].push_back(n2);
        adj[nodetoll(n2)].push_back(n1);
    }

    queue<state> q;
    q.push({{'t',0},'q'});
    unordered_set<ll> seen;
    seen.reserve(6000000);
    int best = 0;

    while(!q.empty()) {
        state here = q.front();
        q.pop();

        node curr = here.first;
        char prev = here.second;

        if(seen.count(statetoll(here))) continue;
        seen.insert(statetoll(here));

        if(curr.first == 't') {
            best = max(best, curr.second);
        }

        for(auto& next : adj[nodetoll(curr)]) {
            if(curr.first == 't' || next.first != prev) {
                q.push({next,curr.first});
            }
        }
    }

    cout << best << endl;
}
