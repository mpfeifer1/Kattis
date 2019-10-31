#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll smallprime = 31;
ll largeprime1 = 1610612741;
ll largeprime2 = 201326611;

ll fastpow(ll base, ll exp, ll mod) {
    base %= mod;
    exp %= mod;
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

ll hashstr(string& s, ll largeprime) {
	ll res = 0;
	for(ll i = 0; i < s.size(); i++) {
		res *= smallprime;
		res %= largeprime;
		res += s[i] - 'a' + 1;
		res %= largeprime;
	}
	return res;
}

vector<ll> getsubhash(string& s, ll largeprime) {
	vector<ll> subhashes;
	
	// The Ith character is the one being ignored
	ll l = 0;
	ll r = 0;

	for(ll i = 0; i < s.size(); i++) {
		r *= smallprime;
		r %= largeprime;
		r += s[i] - 'a' + 1;
		r %= largeprime;
	}
 	
	for(ll i = 0; i < s.size(); i++) {
		// Remove from the front of R
		r -= (fastpow(smallprime, (s.size()-i-1), largeprime) * (s[i] - 'a' + 1)) % largeprime;
		while(r < 0) r += largeprime;

		// Build string from the two
		ll mid = r + (l * fastpow(smallprime, (s.size()-i-1), largeprime)) % largeprime;
		mid %= largeprime;
		subhashes.push_back(mid);

		// Debugging
		//cout << s << " missing char " << i << " hashes to " << mid << endl;

		// Add to end of L
		l *= smallprime;
		l %= largeprime;
		l += s[i] - 'a' + 1;
		l %= largeprime;
	}

	return subhashes;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;

	set<pair<ll,ll>> words;
	vector<string> v(n);
	for(auto& i : v) {
		cin >> i;
		pair<ll,ll> val = {hashstr(i,largeprime1),hashstr(i,largeprime2)};
		words.insert(val);
		//cout << i << " hashed to " << hashstr(i) << endl;
	}

	bool printed = false;
	for(auto i : v) {
		vector<ll> subhash1 = getsubhash(i,largeprime1);
		vector<ll> subhash2 = getsubhash(i,largeprime2);
		for(int j = 0; j < subhash1.size(); j++) {
			if(words.count({subhash1[j],subhash2[j]}) > 0) {
				cout << i << endl;
				printed = true;
				break;
			}
		}
	}	
	if(!printed) {
		cout << "NO TYPOS" << endl;
	}
}
