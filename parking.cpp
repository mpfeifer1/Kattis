#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int a1, a2, a3;
	int d1, d2, d3;

	cin >> a1 >> d1;
	cin >> a2 >> d2;
	cin >> a3 >> d3;

	int cost = 0;
	for(int i = 1; i <= 100; i++) {
		int parked = 0;

		if(a1 <= i && i < d1) {
			parked++;
		}
		if(a2 <= i && i < d2) {
			parked++;
		}
		if(a3 <= i && i < d3) {
			parked++;
		}

		if(parked == 1) {
			cost += a;
		}
		if(parked == 2) {
			cost += 2*b;
		}
		if(parked == 3) {
			cost += 3*c;
		}

	}

	cout << cost << endl;
}
