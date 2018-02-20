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





struct score {
    int team=0;
    int solved=0;
    int penalty=0;
};

bool operator< (const score& lhs, const score& rhs) {
    if(lhs.solved == rhs.solved) {
        if(lhs.penalty == rhs.penalty) {
            return lhs.team < rhs.team;
        }
        return lhs.penalty < rhs.penalty;
    }
    return lhs.solved > rhs.solved;
}

int main() {
    //file();
    fast();

    int n, m;
    cin >> n >> m;

    map<int,score> ref;
    indexed_set<score> s;

    for(int i = 0; i < n; i++) {
        score temp;
        temp.team = i+1;
        ref[i+1] = temp;
        s.insert(temp);
    }

    score fav;
    fav.team = 1;

    for(int i = 0; i < m; i++) {
        int t, penalty;
        cin >> t >> penalty;

        score temp = ref[t];
        ref.erase(t);
        s.erase(temp);

        temp.solved++;
        temp.penalty += penalty;

        ref[t] = temp;
        s.insert(temp);

        if(t == 1) {
            fav = temp;
        }

        cout << s.order_of_key(fav)+1 << endl;
    }

    return 0;
}
