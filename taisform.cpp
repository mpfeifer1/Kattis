#include <bits/stdc++.h>

using namespace std;


int main() {
	double total = 0;
	int n;
	cin >> n;
	vector<pair<double,double>> pairs(n);

	for(auto& i : pairs) {
		cin >> i.first >> i.second;
	}
	
	for(int i = 1; i < n; i++) {
		pair<double,double> p1,p2;
		p1 = pairs[i-1];
		p2 = pairs[i];

		total += (p1.second+p2.second) * (p2.first - p1.first) / 2;
	}	

	cout << fixed;
	cout.precision(10);

	cout << total / 1000 << endl;
}
