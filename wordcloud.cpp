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





int ceildiv(int top, int bot) {
    return (top + bot - 1) / bot;
}

struct word {
    string word;
    int freq;
    int fontsize;
    int width;
    int height;
};

bool cmp(word& w1, word& w2) {
    return w1.word < w2.word;
}

int main() {
    //file();
    //fast();

    int n, m;
    int currcase = 1;
    while(cin >> n && cin >> m && n != 0 && m != 0) {
        vector<word> v;
        int maxfreq = 0;
        for(int i = 0; i < m; i++) {
            word w;
            cin >> w.word >> w.freq;
            maxfreq = max(maxfreq, w.freq);
            if(w.freq >= 5) {
                v.pb(w);
            }
        }

        for(auto& i : v) {
            i.fontsize = 8 + ceildiv(40*(i.freq-4), (maxfreq-4));
            i.height = i.fontsize;
            i.width = ceildiv(9 * i.word.length() * i.height , 16);
        }

        /*
        for(auto& i : v) {
            cout << i.width << " " << i.height << endl;
        }
        */

        int currwidth = 0;
        int totalheight = 0;
        int currheight = 0;

        for(auto& i : v) {
            if(currwidth + i.width > n) {
                totalheight += currheight;
                currwidth = 0;
                currheight = 0;
            }

            currwidth += i.width + 10;
            currheight = max(currheight, i.height);
        }
        totalheight += currheight;

        cout << "CLOUD " << currcase << ": " << totalheight << endl;
        currcase++;
    }

    return 0;
}
