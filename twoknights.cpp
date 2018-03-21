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





struct state {
    int x1;
    int y1;

    int x2;
    int y2;

    int len;
};

bool inrange(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < 10) && (y < 4);
}

int coordtopos(int x, int y) {
    return y*10+x;
}

bool checkvis(vector<vector<vector<bool>>>& vis, state s) {
    int pos1 = coordtopos(s.x1,s.y1);
    int pos2 = coordtopos(s.x2,s.y2);
    bool ret = vis[pos1][pos2][s.len];
    vis[pos1][pos2][s.len] = true;
    return ret;
}

char getchar(vector<vector<char>>& upper, vector<vector<char>>& lower, int mx, int my, int sx, int sy) {
    //cout << sx << " " << sy << " " << mx << " " << my << endl;
    if(lower[sy][sx] == '^') {
        return upper[my][mx];
    }
    else {
        return lower[my][mx];
    }
}

int main() {
    //file();
    //fast();

    vector<vector<char>> upper = {{'Q','W','E','R','T','Y','U','I','O','P'},
                                  {'A','S','D','F','G','H','J','K','L',':'},
                                  {'Z','X','C','V','B','N','M','<','>','?'},
                                  {'^','^',' ',' ',' ',' ',' ',' ','^','^'}};

    vector<vector<char>> lower = {{'q','w','e','r','t','y','u','i','o','p'},
                                  {'a','s','d','f','g','h','j','k','l',';'},
                                  {'z','x','c','v','b','n','m',',','.','/'},
                                  {'^','^',' ',' ',' ',' ',' ',' ','^','^'}};

    vector<pair<int,int>> movement = {{-1,2},
                                      {1,2},
                                      {-1,-2},
                                      {1,-2},
                                      {-2,1},
                                      {2,1},
                                      {-2,-1},
                                      {2,-1}};

    string s;
    while(getline(cin,s) && s != "*") {
        vector<vector<vector<bool>>> vis;
        vis.resize(40, vector<vector<bool>>(40, vector<bool>(101)));

        state init;
        init.x1 = 0;
        init.y1 = 3;
        init.x2 = 9;
        init.y2 = 3;
        init.len = 0;

        queue<state> q;
        q.push(init);

        while(!q.empty()) {
            // Get next state
            state curr = q.front();
            q.pop();

            // Check visited, mark visited
            if(checkvis(vis, curr)) {
                continue;
            }

            // If done, break
            if(curr.len == s.length()) {
                break;
            }

            // Try all next states for knight 1
            for(auto i : movement) {
                int nextx = curr.x1 + i.first;
                int nexty = curr.y1 + i.second;

                // If can't move there, skip
                if(!inrange(nextx,nexty) || (nextx == curr.x2 && nexty == curr.y2)) {
                    continue;
                }

                // If new char is OK
                char c = getchar(upper,lower,nextx,nexty,curr.x2,curr.y2);
                if(c == '^') {
                    state newstate;
                    newstate.x1 = nextx;
                    newstate.y1 = nexty;
                    newstate.x2 = curr.x2;
                    newstate.y2 = curr.y2;
                    newstate.len = curr.len;
                    q.push(newstate);
                }
                if(c == s[curr.len]) {
                    state newstate;
                    newstate.x1 = nextx;
                    newstate.y1 = nexty;
                    newstate.x2 = curr.x2;
                    newstate.y2 = curr.y2;
                    newstate.len = curr.len+1;
                    q.push(newstate);
                }
            }

            // Try all next states for knight 2
            for(auto i : movement) {
                int nextx = curr.x2 + i.first;
                int nexty = curr.y2 + i.second;

                // If can't move there, skip
                if(!inrange(nextx,nexty) || (nextx == curr.x1 && nexty == curr.y1)) {
                    continue;
                }

                // If new char is OK
                char c = getchar(upper,lower,nextx,nexty,curr.x1,curr.y1);
                if(c == '^') {
                    state newstate;
                    newstate.x2 = nextx;
                    newstate.y2 = nexty;
                    newstate.x1 = curr.x1;
                    newstate.y1 = curr.y1;
                    newstate.len = curr.len;
                    q.push(newstate);
                }
                if(c == s[curr.len]) {
                    state newstate;
                    newstate.x2 = nextx;
                    newstate.y2 = nexty;
                    newstate.x1 = curr.x1;
                    newstate.y1 = curr.y1;
                    newstate.len = curr.len+1;
                    q.push(newstate);
                }
            }
        }

        // Check if we can write poem
        bool works = false;
        for(int i = 0; i < 40; i++) {
            for(int j = 0; j < 40; j++) {
                if(vis[i][j][s.length()]) {
                    works = true;
                }
            }
        }

        // Print answer
        if(works) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }

    return 0;
}
