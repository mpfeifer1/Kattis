#include <iostream>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;

	int theirs = 52 - n;

	if(n > theirs) {
		cout << "possible" << endl;
	}
	else if(n == theirs) {
		map<char, int> maxfound;
		map<char, int> count;

		maxfound['C'] = 0;
		maxfound['H'] = 0;
		maxfound['D'] = 0;
		maxfound['S'] = 0;

		count['S'] = 0;
		count['C'] = 0;
		count['D'] = 0;
		count['H'] = 0;


		for(int i = 0; i  < n; i++) {
		 	char temp1;
			int temp2;
			cin >> temp2 >> temp1;

			count[temp1]++;

			maxfound[temp1] = max(maxfound[temp1], temp2);
		}
		bool possible = false;

		if(maxfound['H'] > count['H']) {
			possible = true;
		}
		if(maxfound['D'] > count['D']) {
			possible = true;
		}
		if(maxfound['C'] > count['C']) {
			possible = true;
		}
		if(maxfound['S'] > count['S']) {
			possible = true;
		}

		if(possible) {
			cout << "possible" << endl;
		}
		else {
			cout << "impossible" << endl;
		}
	}
	else {
		cout << "impossible" << endl;
	}
}
