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





bool valid(string s) {
    int hi = stoi(s.substr(0,2));
    int lo = stoi(s.substr(3,2));
    return hi < 24 && lo < 60;
}

// Takes in a valid time string, adds each next possibility
void addnext(map<string,set<string>>& adj, string s) {
    string next = s;

    next[0] = s[0] + 1;
    if(next[0] > '9') next[0] = '0';
    if(valid(next)) adj[s].insert(next);

    next[0] = s[0] - 1;
    if(next[0] < '0') next[0] = '9';
    if(valid(next)) adj[s].insert(next);

    next[0] = s[0];



    next[1] = s[1] + 1;
    if(next[1] > '9') next[1] = '0';
    if(valid(next)) adj[s].insert(next);

    next[1] = s[1] - 1;
    if(next[1] < '0') next[1] = '9';
    if(valid(next)) adj[s].insert(next);

    next[1] = s[1];



    next[3] = s[3] + 1;
    if(next[3] > '9') next[3] = '0';
    if(valid(next)) adj[s].insert(next);

    next[3] = s[3] - 1;
    if(next[3] < '0') next[3] = '9';
    if(valid(next)) adj[s].insert(next);

    next[3] = s[3];



    next[4] = s[4] + 1;
    if(next[4] > '9') next[4] = '0';
    if(valid(next)) adj[s].insert(next);

    next[4] = s[4] - 1;
    if(next[4] < '0') next[4] = '9';
    if(valid(next)) adj[s].insert(next);

    next[4] = s[4];
}

int main() {
    //file();
    //fast();

    string n1, n2;
    cin >> n1 >> n2;

    map<string, set<string>> adj;

    string s = "00:00";
    for(int i = 0; i < 3; i++) {
        s[0] = i + '0';
        for(int j = 0; j < 10; j++) {
            s[1] = j + '0';
            for(int k = 0; k < 6; k++) {
                s[3] = k + '0';
                for(int l = 0; l < 10; l++) {
                    s[4] = l + '0';

                    if(!valid(s)) {
                        continue;
                    }

                    addnext(adj, s);
                }
            }
        }
    }

    map<string,string> prev;
    map<string,int> dist;
    dist[n1] = 1;

    queue<string> q;
    q.push(n1);

    while(!q.empty()) {
        string curr = q.front();
        q.pop();

        for(auto i : adj[curr]) {
            if(dist.count(i) == 0) {
                prev[i] = curr;
                dist[i] = dist[curr]+1;
                q.push(i);
            }
        }
    }

    vector<string> ans;
    string it = n2;
    while(it != n1) {
        ans.pb(it);
        it = prev[it];
    }
    ans.pb(it);

    cout << dist[n2] << endl;
    reverse(all(ans));
    for(auto i : ans) {
        cout << i << endl;
    }

    return 0;
}
