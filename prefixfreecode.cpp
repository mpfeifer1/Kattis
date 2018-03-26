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



// Calculate powers in log(n) time
ll fastpow(ll base, ll exp, ll mod) {
    ll res = 1;
    while(exp > 0) {
        if((exp & 1) == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }

    return res % mod;
}

// Set up memory for factorials and inverse factorials
const ll MAXN = 1000000;
ll factarr[MAXN+1];
ll ifactarr[MAXN+1];

// Generate all factorials and inverse factorials
void generate() {
    factarr[0] = 1;
    for(ll i = 1; i <= MAXN; i++) {
        factarr[i] = (factarr[i-1] * i) % mod;
    }
    ifactarr[MAXN] = fastpow(factarr[MAXN], mod-2, mod);
    for(int i = MAXN-1; i >= 0; i--) {
        ifactarr[i] = (ifactarr[i+1] * (i+1)) % mod;
    }
}

// Returns n!
ll fact(ll n) {
    return factarr[n];
}

// Returns modular inverse of n!
ll ifact(ll n) {
    return ifactarr[n];
}

// Returns N choose K
ll ncr(ll n, ll r) {
    if(n < 0 || r < 0 || r > n) return 0;
    ll ans = (fact(n) * ifact(r)) % mod;
    return (ans * ifact(n-r)) % mod;
}

// Returns N permute K
ll npr(ll n, ll r) {
    if(n < 0 || r < 0 || r > n) return 0;
    return (fact(n) * ifact(n-r)) % mod;
}



// Define trie
struct str_trie;
struct str_trie {
    map<char,str_trie> next;
};

// Insert word into trie
void insert(str_trie& n, string& s) {
    if(s.empty()) {
        return;
    }
    char c = s.back();
    s.pop_back();
    insert(n.next[c], s);
}

// Debugging - prints all words in trie alphabetically
void print(str_trie& t, string& curr) {
    if(t.next.size() == 0) {
        cout << curr << endl;
        return;
    }
    for(auto& i : t.next) {
        curr.pb(i.first);
        print(i.second, curr);
        curr.pop_back();
    }
}



int main() {
    //file();
    fast();

    // Prepare factorials for npr
    generate();

    // Read in input
    int n, m;
    cin >> n >> m;

    // Set up storage for strings
    indexed_set<string> s;
    str_trie t;

    // Read in all dictionary strings
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        s.insert(temp);
        reverse(all(temp));
        insert(t, temp);
    }

    // Read in query string
    string query;
    cin >> query;
    vector<string> splitquery;

    // Split up all words using trie
    string here = "";
    str_trie* idx = &t;
    for(int i = 0; i < query.size(); i++) {
        // Fix weird bug with overstepping string?
        if(!isalpha(query[i])) {
            continue;
        }

        // Add to current string
        here.pb(query[i]);
        idx = &idx->next[query[i]];

        // If nowhere to go in trie, must be completed word
        if(idx->next.size() == 0) {
            // Add this word, prepare next
            splitquery.pb(here);
            here = "";
            idx = &t;
        }
    }

    // For each word, calculate
    ll pos = 0;
    ll processed = 0;
    for(auto& i : splitquery) {
        // Keep track of how many strings processed
        processed++;

        // Get number of string before this one
        ll order = s.order_of_key(i);

        // Calulate total number of strings of length m-processed before this
        ll permute = npr(n-processed, m-processed);

        // Add in the position
        pos += order * permute;
        pos %= mod;

        // Remove from dictionary
        s.erase(i);
    }

    // Print answer
    cout << (pos+1) % mod << endl;

    return 0;
}
