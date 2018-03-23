// Michael Pfeifer
// Version 04, 2018/02/17

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ld  pi   = 4.0*atanl(1.0);
const int iinf = 1e9 + 10;
const ll  inf  = 1e18 + 10;
const int mod  = 1000000007;
const ld  prec = .000001;

#define enld endl
#define endl '\n'
#define pb push_back
#define debug(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define umap unordered_map
#define uset unordered_set

template<class TIn>
using indexed_set = tree<
        TIn, null_type, less<TIn>,
        rb_tree_tag, tree_order_statistics_node_update>;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void file() {
    auto a = freopen("a.in",  "r", stdin);
    auto b = freopen("a.out", "w", stdout);
    if(!a || !b) cout << "uh oh" << endl;
}





vector<vector<int>> increment(vector<vector<int>> v, int x, int y) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            v[i][j] += 4;
        }
    }

    for(int i = 0; i < 3; i++) {
        v[x][i]--;
    }

    for(int i = 0; i < 3; i++) {
        v[i][y]--;
    }

    v[x][y]++;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            v[i][j] %= 4;
        }
    }

    return v;
}

int main() {
    //file();
    fast();

    map<vector<vector<int>>, int> dist;

    queue<vector<vector<int>>> q;
    q.push({{0,0,0},{0,0,0},{0,0,0}});
    dist[{{0,0,0},{0,0,0},{0,0,0}}] = 0;

    while(!q.empty()) {
        vector<vector<int>> curr = q.front();
        q.pop();

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                vector<vector<int>> next = increment(curr, i, j);
                if(dist.count(next) == 0) {
                    dist[next] = dist[curr]+1;
                    q.push(next);
                }
            }
        }
    }

    vector<vector<int>> end;
    end.resize(3, vector<int>(3));
    for(auto& i : end) {
        for(auto& j : i) {
            cin >> j;
        }
    }

    if(dist.count(end) == 0) {
        cout << -1 << endl;
    }
    else {
        cout << dist[end] << endl;
    }

    return 0;
}
