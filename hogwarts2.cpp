#include <bits/stdc++.h>

using namespace std;

int n;

int convert(int i, int j) {
	return i * (n+1) + j;
}

int main() {
	cin >> n;

	vector<vector<int>> adj1;
	vector<vector<int>> adj2;

	adj1.push_back({0,0,0,0});
	adj2.push_back({0,0,0,0});

	for(int i = 0; i < n; i++) {
		vector<int> v(4);
		for(auto& j : v) cin >> j;
		adj1.push_back(v);
	}

	for(int i = 0; i < n; i++) {
		vector<int> v(4);
		for(auto& j : v) cin >> j;
		adj2.push_back(v);
	}

	vector<vector<int>> adj((n+1)*(n+1));
	for(int k = 0; k < 4; k++) {
		for(int i = 0; i <= n; i++) {
			for(int j = 0; j <= n; j++) {
				int ni = adj1[i][k];
				int nj = adj2[j][k];

				adj[convert(i,j)].push_back(convert(ni,nj));
			}
		}
	}

	vector<bool> vis((n+1)*(n+1),false);

	queue<int> q;
	q.push(convert(1,1));

	while(!q.empty()) {
		int curr = q.front();
		q.pop();

		if(vis[curr]) continue;
		vis[curr] = true;

		for(auto next : adj[curr]) {
			q.push(next);
		}
	}

	bool sworks = false;
	bool works = true;

	for(int i = 0; i <= n; i++) {
		if(vis[convert(n,i)]) sworks = true;
	}
	for(int i = 0; i < n; i++) {
		if(vis[convert(n,i)]) works = false;
	}

	if(!sworks) cout << "Impossible" << endl;
	else if(works) cout << "Yes" << endl;
	else cout << "No" << endl;
}
