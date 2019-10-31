#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, p, d;
	cin >> n >> p >> d;

	string s;
	cin >> s;
	s += s;

	int tired = 0;
	int w = 0;
	int z = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == 'W') w++;
		else z++;

		if(i - p >= 0) {
			if(s[i-p] == 'W') w--;
			else z--;
		}

		if(i >= n) {
			if(z < d) {
				tired++;
			}
		}
	}

	cout << tired << endl;
}
