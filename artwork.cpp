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





int n, m, q;

struct query {
    int x1, x2, y1, y2;
};

int find(vector<int>& d, int a) {
    if(d[a] == -1) {
        return a;
    }
    return d[a] = find(d, d[a]);
}

void join(vector<int>& d, int a, int b) {
    a = find(d,a);
    b = find(d,b);
    if(a == b) {
        return;
    }
    d[a] = b;
}

int spot(int i, int j) {
    return i*n+j;
}

void alljoin(vector<vector<int>>& v, vector<int>& d, int i, int j, int& sections) {
    if(i > 0) {
        if(v[i-1][j] == 0) {
            if(find(d, spot(i-1,j)) != find(d, spot(i,j))) {
                join(d, spot(i-1,j), spot(i,j));
                sections--;
            }
        }
    }
    if(j > 0) {
        if(v[i][j-1] == 0) {
            if(find(d, spot(i,j-1)) != find(d, spot(i,j))) {
                join(d, spot(i,j-1), spot(i,j));
                sections--;
            }
        }
    }
    if(i < m-1) {
        if(v[i+1][j] == 0) {
            if(find(d, spot(i+1,j)) != find(d, spot(i,j))) {
                join(d, spot(i+1,j), spot(i,j));
                sections--;
            }
        }
    }
    if(j < n-1) {
        if(v[i][j+1] == 0) {
            if(find(d, spot(i,j+1)) != find(d, spot(i,j))) {
                join(d, spot(i,j+1), spot(i,j));
                sections--;
            }
        }
    }
}

void count(vector<vector<int>>& v, vector<int>& d, query& q, int& sections) {
    if(q.x1 == q.x2) {
        for(int i = min(q.y1,q.y2); i <= max(q.y1,q.y2); i++) {
            if(v[i][q.x1] == 0) {
                sections++;
                alljoin(v, d, i, q.x1, sections);
            }
        }
    }
    else {
        for(int i = min(q.x1,q.x2); i <= max(q.x1,q.x2); i++) {
            if(v[q.y1][i] == 0) {
                sections++;
                alljoin(v, d, q.y1, i, sections);
            }
        }
    }
}

void process(vector<vector<int>>& v, query q, int delta) {
    if(q.x1 == q.x2) {
        for(int i = min(q.y1,q.y2); i <= max(q.y1,q.y2); i++) {
            v[i][q.x1] += delta;
        }
    }
    else {
        for(int i = min(q.x1,q.x2); i <= max(q.x1,q.x2); i++) {
            v[q.y1][i] += delta;
        }
    }
}

int main() {
    //file();
    fast();

    // Take in input
    cin >> n >> m >> q;
    vector<vector<int>> v;
    v.resize(m, vector<int>(n, 0));

    // Save all the queries for use later
    vector<query> queries;
    for(int i = 0; i < q; i++) {
        query q;
        cin >> q.x1 >> q.y1 >> q.x2 >> q.y2;
        q.x1--; q.y1--;
        q.x2--; q.y2--;
        queries.pb(q);
    }

    // Process all the queries
    for(auto& i : queries) {
        process(v, i, 1);
    }

    // Count how many white squares there are
    int sections = 0;
    vector<int> d(n*m, -1);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(v[i][j] == 0) {
                sections++;
                if(i > 0 && v[i-1][j] == 0) {
                    if(find(d,spot(i-1,j)) != find(d,spot(i,j))) {
                        join(d, spot(i-1,j), spot(i,j));
                        sections--;
                    }
                }
                if(j > 0 && v[i][j-1] == 0) {
                    if(find(d,spot(i,j-1)) != find(d,spot(i,j))) {
                        join(d, spot(i,j-1), spot(i,j));
                        sections--;
                    }
                }
            }
        }
    }

    // For each query, add answer, remove, check white squares
    vector<int> ans;
    reverse(all(queries));
    for(auto i : queries) {
        ans.pb(sections);
        process(v, i, -1);

        /*
        for(auto& j : v) {
            for(auto& k : j) {
                cout << k;
            }
            cout << endl;
        }
        cout << endl;
        */

        count(v, d, i, sections);
    }

    // Print out all the answers
    reverse(all(ans));
    for(auto i : ans) {
        cout << i << endl;
    }

    return 0;
}
