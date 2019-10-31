#include <bits/stdc++.h>

using namespace std;
int inf = 100000000;

int main() {
	int n, m;
	cin >> n >> m;

	// Read in grid
	vector<string> grid(n);
	for(auto& i : grid) cin >> i;

	// Find start points
	int vi, vj, ji, jj;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(grid[i][j] == 'V') {
				vi = i;
				vj = j;
			}
			if(grid[i][j] == 'J') {
				ji = i;
				jj = j;
			}
		}
	}

	// Calculate how for each spot is to the nearest tree
	vector<vector<int>> totree(n,vector<int>(m,inf));
	queue<pair<int,int>> treeq;
	vector<int> dx = {1,-1,0,0};
	vector<int> dy = {0,0,1,-1};

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(grid[i][j] == '+') {
				totree[i][j] = 0;
				treeq.push({i,j});
			}
		}
	}

	while(!treeq.empty()) {
		pair<int,int> curr = treeq.front();
		treeq.pop();

		for(int i = 0; i < 4; i++) {
			int currx = curr.first + dx[i];
			int curry = curr.second + dy[i];

			if(currx < 0 || currx >= n) continue;
			if(curry < 0 || curry >= m) continue;
			if(totree[currx][curry] != inf) continue;

			totree[currx][curry] = totree[curr.first][curr.second] + 1;
			treeq.push({currx,curry});
		}
	}

	for(int dist = n*m+5; dist >= 0; dist--) {
		// See if we can make a path in this dist or better

		if(totree[vi][vj] < dist) continue;
		if(totree[ji][jj] < dist) continue;

		vector<vector<bool>> vis(n,vector<bool>(m,false));
		queue<pair<int,int>> bestq;
		bestq.push({vi,vj});

		while(!bestq.empty()) {
			pair<int,int> curr = bestq.front();
			bestq.pop();

			if(vis[curr.first][curr.second]) {
				continue;
			}
			vis[curr.first][curr.second] = true;

			for(int i = 0; i < 4; i++) {
				int nextx = curr.first + dx[i];
				int nexty = curr.second + dy[i];

				if(nextx < 0 || nextx >= n) continue;
				if(nexty < 0 || nexty >= m) continue;
				if(totree[nextx][nexty] < dist) continue;

				bestq.push({nextx,nexty});
			}
		}

		if(vis[ji][jj]) {
			cout << dist << endl;
			return 0;
		}
			
	}

}
