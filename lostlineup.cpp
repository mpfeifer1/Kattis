#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> ans(n);
	ans[0] = 1;

	for(int i = 2; i <= n; i++) {
		int t;
		cin >> t;
		ans[t+1] = i;
	}

	for(auto i : ans) {
		cout << i << " ";
	}
	cout << endl;
}
