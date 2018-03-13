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





bool isprime(int n) {
    if(n < 2) {
        return false;
    }
    if(n == 2) {
        return true;
    }

    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int total = 0;
int curr = 0;
int numleft = 0;
vector<int> numcount;
set<int> prime;

void process() {
    if(isprime(curr)) {
        prime.insert(curr);
    }

    if(numleft == 0) {
        return;
    }

    for(int i = 0; i < 10; i++) {
        if(numcount[i] > 0) {
            curr *= 10;
            curr += i;
            numleft--;
            numcount[i]--;

            process();

            numcount[i]++;
            numleft++;
            curr /= 10;
        }
    }
}

int main() {
    //file();
    fast();

    int cases;
    cin >> cases;
    while(cases--) {
        string s;
        cin >> s;

        total = 0;
        numleft = 0;
        curr = 0;
        prime.clear();
        numcount.clear();
        numcount.resize(10,0);

        for(auto i : s) {
            numcount[i-'0']++;
            numleft++;
        }

        process();
        cout << prime.size() << endl;
    }

    return 0;
}
