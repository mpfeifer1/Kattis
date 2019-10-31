#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ll n, v, h;
	cin >> n >> v >> h;

	cout << max(v,n-v)*max(h,n-h)*4 << endl;
}
