// Michael Pfeifer
// Version 04, 2018/02/17

// IGNORE MY HEADER FILE - NONE OF THIS MATTERS TO YOU
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
    fast();

    // THE ACTUAL CODE STARTS HERE

    // While we're able to get new test cases, solve them
    ll n;
    while(cin >> n && n != 0) {

        // Create a list of prices size n
        vector<ll> price(n);

        // Calculate the sum of all prices
        ll sum = 0;

        // For each price in the input
        for(auto& i : price) {
            // Take in the dollars and cents
            ll lo, hi;
            cin >> hi;
            cin.ignore();
            cin >> lo;

            // Set ith value in array to price in cents
            i = hi*100+lo;

            // Add that price to the sum
            sum += i;
        }

        // The average (rounded down) is the sum / the people
        ll avg = sum / n;

        // The leftover pennies are the sum % the people
        sum %= n;

        // Get a list of the averaged prices (size n)
        vector<ll> averaged(n);

        for(int i = 0; i < n; i++) {
            // Set ith element to the average
            averaged[i] = avg;

            // Increment exactly 'leftover' elements
            if(i < sum) {
                averaged[i]++;
            }
        }

        // Sort both the price and the averaged prices
        sort(all(price));
        sort(all(averaged));

        // The total exchanged is zero
        ll total = 0;
        for(int i = 0; i < n; i++) {
            // Debugging print that should help
            //cout << price[i] << "\t" << averaged[i] << endl;

            // The price at the next element is the difference that person has
            total += abs(price[i] - averaged[i]);
        }

        // Don't want to double-count everything!
        total /= 2;

        // So we have 2 digits of precision
        cout << fixed;
        cout.precision(2);

        // Print the answer in dollars
        cout << "$" << (ld)total/100 << endl;
    }

    return 0;
}
