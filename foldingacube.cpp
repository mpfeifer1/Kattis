#include <bits/stdc++.h>

using namespace std;

struct cube {
	int u = 0;
	int d = 1;
	int l = 2;
	int r = 3;
	int f = 4;
	int b = 5;
};

cube rotl(cube c) {
	int t = c.d;
	c.d = c.l;
	c.l = c.u;
	c.u = c.r;
	c.r = t;
	return c;
}

cube rotd(cube c) {
	int t = c.d;
	c.d = c.f;
	c.f = c.u;
	c.u = c.b;
	c.b = t;
	return c;
}

vector<int> dx = {1,-1,0,0};
vector<int> dy = {0,0,1,-1};

bool bfs(vector<string>& grid, int si, int sj, cube c) {
	queue<pair<int,int>> q;
	queue<cube> state;
	q.push({si,sj});
	state.push(c);
 
	set<int> used;
	
	while(!q.empty()) {
		cube c = state.front();
		pair<int,int> curr = q.front();

		q.pop();
		state.pop();

		if(grid[curr.first][curr.second] != '#') continue;
		grid[curr.first][curr.second] = '0' + c.d;
		used.insert(c.d);

		for(int i = 0; i < 4; i++) {
			int nexti = curr.first + dx[i];
			int nextj = curr.second + dy[i];
			if(nexti < 0 || nexti > 5) continue;
			if(nextj < 0 || nextj > 5) continue;

			q.push({nexti,nextj});
			if(i == 0) state.push(rotd(c));
			if(i == 1) state.push(rotd(rotd(rotd(c))));
			if(i == 2) state.push(rotl(rotl(rotl(c))));
			if(i == 3) state.push(rotl(c));
		}
	}

 	return used.size() == 6;
}

int main() {
	vector<string> grid(6);
	for(auto& i : grid) {
		cin >> i;
	}

	cube c;
	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < 6; j++) {
			if(grid[i][j] == '#') {
				if(bfs(grid,i,j,c)) cout << "can fold" << endl;
				else cout << "cannot fold" << endl;
				return 0;
			}	
		}
	}
}
