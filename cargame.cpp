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





bool match(string& s, string& pat) {
    bool f1 = false;
    bool f2 = false;

    for(auto& i : s) {
        if(i == pat[2] && f2) {
            return true;
        }
        if(i == pat[1] && f1) {
            f2 = true;
        }
        if(i == pat[0]) {
            f1 = true;
        }
    }

    return false;
}

int main() {
    //file();
    fast();

    int n, m;
    cin >> n >> m;

    vector<string> v(n);
    map<char, bool> ininput;
    for(char i = 'a'; i <= 'z'; i++) {
        ininput[i] = false;
    }
    for(auto& s : v) {
        cin >> s;
        for(auto& i : s) {
            ininput[i] = true;
        }
    }

    map<string, int> memo;

    for(int i = 0; i < m; i++) {
        // Take in input, make it lowercase
        string s;
        cin >> s;
        for(auto& j : s) {
            j = tolower(j);
        }

        // If a char isn't in the input, skip it
        if(!ininput[s[0]] || !ininput[s[1]] || !ininput[s[2]]) {
            cout << "No valid word" << endl;
            continue;
        }

        // If in memo as bad, print
        if(memo.count(s) > 0 && memo[s] == -1) {
            cout << "No valid word" << endl;
            continue;
        }

        // If in memo, skip it
        if(memo.count(s) > 0) {
            cout << v[memo[s]] << endl;
            continue;
        }

        // If not in memo, find it
        bool found = false;
        int idx = 0;
        for(auto& j : v) {
            if(match(j, s)) {
                found = true;
                break;
            }
            idx++;
        }

        // If found, add to memo, print
        if(found) {
            memo[s] = idx;
            cout << v[idx] << endl;
        }

        // Else say not found, add to bad memo
        else {
            memo[s] = -1;
            cout << "No valid word" << endl;
        }
    }

    return 0;
}
