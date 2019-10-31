#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ll n, d;
	cin >> n >> d;
	map<ll,ll> m;
	for(int i = 0; i < n; i++) {
		ll t;
		cin >> t;
		m[t/d]++;
	}
	ll total = 0;
	for(auto i : m) {
		ll t = i.second;
		total += t * (t-1) / 2;
	}
	cout << total << endl;
}
