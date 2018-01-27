// Michael Pfeifer
// Version 02, 2018/01/17

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

ll readint(){
    char r;
    bool start=false,neg=false;
    ll ret=0;
    while(true){
        r=getchar();
        if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
            continue;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && start){
            break;
        }
        if(start)ret*=10;
        start=true;
        if(r=='-')neg=true;
        else ret+=r-'0';
    }
    if(!neg) return ret;
    else return -ret;
}





int main() {
    //file();
    fast();

    int n, m;
    while(cin >> n && cin >> m) {
        vector<set<int>> sets(n+1);
        vector<int> place(n+1);
        vector<ll> sum(n+1);

        for(int i = 0; i < n+1; i++) {
            sets[i].insert(i);
            place[i] = i;
            sum[i] = i;
        }

        while(m--) {
            int q;
            cin >> q;

            // Join
            if(q == 1) {
                int n1, n2;
                cin >> n1 >> n2;

                n1 = place[n1];
                n2 = place[n2];

                if(n1 == n2) {
                    continue;
                }

                if(sets[n1].size() > sets[n2].size()) {
                    for(auto i : sets[n2]) {
                        sets[n1].insert(i);
                        place[i] = n1;
                    }
                    sets[n2].clear();
                    sum[n1] += sum[n2];
                    sum[n2] = 0;
                }
                else {
                    for(auto i : sets[n1]) {
                        sets[n2].insert(i);
                        place[i] = n2;
                    }
                    sets[n1].clear();
                    sum[n2] += sum[n1];
                    sum[n1] = 0;
                }
            }

            // Move
            if(q == 2) {
                int n1, n2;
                cin >> n1 >> n2;

                sum[place[n1]] -= n1;
                sum[place[n2]] += n1;

                sets[place[n1]].erase(n1);
                sets[place[n2]].insert(n1);
                place[n1] = place[n2];
            }

            // Print set
            if(q == 3) {
                int n1;
                cin >> n1;
                cout << sets[place[n1]].size() << " ";
                cout << sum[place[n1]] << endl;
            }

            /*
            for(auto i : sets) {
                cout << "{ ";
                for(auto j : i) {
                    cout << j << ",";
                }
                cout << "} ";
            }
            cout << endl;
            */
        }
    }
}
