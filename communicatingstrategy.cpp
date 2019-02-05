#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 60;
ll mod = 1000000007;

//returns x such that x*a == 1 (mod b)
//x only exists if gcd(a, b) == 1
ll modinverse(ll a, ll b = mod){
    return 1<a ? b - modinverse(b%a,a)*b/a : 1;
}

void clean(ll& n) {
    while(n < mod) n += mod;
    n %= mod;
}

int main() {
    ll n;
    cin >> n;

    vector<vector<ll>> memo;
    memo.resize(n+1,vector<ll>(n+1,0));

    cout << "1 1 1" << endl;
    ll t1, t2;
    cin >> t1 >> t2;
    memo[1][1] = t2;

    vector<int> ans;
    ans.push_back(t2);

    for(ll i = 2; i <= n; i++) {
        cout << "1 1 " << i << endl;
        ll t1, t2;
        cin >> t1 >> t2;

        ll val;

        if(t1 == 1) {
            val = t2 - memo[i-1][1];
            clean(val);
        }
        else if(t1 == i) {
            val = t2 * modinverse(memo[i-1][i-1]);
            clean(val);
        }
        else {
            val = (t2 - memo[i-1][t1]);
            clean(val);
            val *= modinverse(memo[i-1][t1-1]);
            clean(val);
        }


        for(int j = 1; j <= i; j++) {
            if(j == 1) {
                memo[i][j] = memo[i-1][j] + val;
                clean(memo[i][j]);
            }
            else if(j == i) {
                memo[i][j] = memo[i-1][j-1] * val;
                clean(memo[i][j]);
            }
            else {
                memo[i][j] = memo[i-1][j] + memo[i-1][j-1] * val;
                clean(memo[i][j]);
            }
        }

        ans.push_back(val);
    }

    cout << "2 ";
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}
