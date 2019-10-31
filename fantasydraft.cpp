#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<vector<string>> preferences(n);
	for(auto& pref : preferences) {
		int t;
		cin >> t;
		for(int i = 0; i < t; i++) {
			string s;
			cin >> s;
			pref.push_back(s);
		}
		reverse(pref.begin(),pref.end());
	}

	map<string,int> torank;
	map<int,string> available;

	int p;
	cin >> p;
	for(int i = 0; i < p; i++) {
		string s;
		cin >> s;

		available[i] = s;
		torank[s] = i;
	}

	vector<vector<string>> selections(k);

	// For each pick
	for(int i = 0; i < k; i++) {
		// For each owner
		for(int j = 0; j < n; j++) {
			// Check through their picks to see if anyone's available
			bool picked = false;
			while(!picked && preferences[j].size() > 0) {
				string pick = preferences[j].back();
				int rank = torank[pick];
				preferences[j].pop_back();
				if(available.count(rank) > 0) {
					selections[j].push_back(pick);
					available.erase(rank);
					picked = true;
				}
			}
			// If they didn't get their selection, give them the best available player
			if(!picked) {
				string pick = available.begin()->second;
				int rank = torank[pick];
				selections[j].push_back(pick);
				available.erase(rank);
			}
		}
	}

	for(auto i : selections) {
		for(auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	
}
