#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	for(auto& i : v) {
		cin >> i;
	}

	int ans = 50;
	int idx = 0;
	for(int i = 2; i < n; i++) {
		if(ans > max(v[i], v[i-2])) {
			ans = max(v[i], v[i-2]);
			idx = i-1;
		}
	}

	cout << idx << " " << ans << endl;
}
