#include <bits/stdc++.h>

using namespace std;

int main() {
	bool printed = false;
	for(int i = 1; i <= 5; i++) {
		string s;
		cin >> s;

		if(s.find("FBI") != -1) {
			cout << i << " ";
			printed = true;
		}
	}

	if(printed) {
		cout << endl;
	}
	else {
		cout << "HE GOT AWAY!" << endl;
	}
}
