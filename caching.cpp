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





int main() {
    //file();
    //fast();

    int c, n, a;
    cin >> c >> n >> a;

    vector<int> access(a);
    for(auto& i : access) {
        cin >> i;
    }

    map<int,set<int>> accesstimes;
    for(int i = 0; i < a; i++) {
        accesstimes[access[i]].insert(i);
    }

    for(auto& i : accesstimes) {
        if(i.second.size() > 0) {
            i.second.erase(i.second.begin());
        }
    }

    set<int> cache;
    set<pair<int,int>> byval;
    set<pair<int,int>> byidx;
    int faults = 0;
    for(int i = 0; i < a; i++) {
        // If not in cache
        if(cache.count(access[i]) == 0) {
            faults++;

            // If cache full
            if(cache.size() == c) {
                // Remove farthest element from set
                pair<int,int> rem = *prev(byidx.end());
                byval.erase({rem.second,rem.first});
                byidx.erase(rem);
                cache.erase(rem.second);
            }
        }

        // If in cache
        else {
            // Remove it from set
            pair<int,int> rem = *byval.lower_bound({access[i],-1});
            byval.erase(rem);
            byidx.erase({rem.second,rem.first});
            cache.erase(rem.first);
        }

        // Find next time
        if(accesstimes[access[i]].size() > 0) {
            int nexttime = *accesstimes[access[i]].begin();
            accesstimes[access[i]].erase(nexttime);

            // Add it to set
            byval.insert({access[i],nexttime});
            byidx.insert({nexttime,access[i]});
            cache.insert(access[i]);
        }
    }

    cout << faults << endl;

    return 0;
}
