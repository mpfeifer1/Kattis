#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	int total = 0;
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;

		if(t < 0) {
			total -= t;
		}
	}

	cout << total << endl;
}
