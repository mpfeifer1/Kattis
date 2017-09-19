#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct spot {
    int f;
    int r;
    int dist;
};

// Checks if a spot is in the board
bool inrange(vector<vector<int>>& v, int i, int j) {
    if(i < 0 || j < 0 || i > 7 || j > 7) {
        return false;
    }
    if(v[i][j] == -1) {
        return true;
    }
    return false;
}

bool compare(string lhs, string rhs) {
    if(lhs[1] == rhs[1]) {
        return lhs[0] < rhs[0];
    }
    return lhs[1] > rhs[1];
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        // Read in data
        char file, rank;
        cin >> file >> rank;
        vector<vector<int>> v;
        v.resize(8, vector<int>(8, -1));

        // Mark first spot
        queue<spot> q;
        q.push({file-'a', rank-'1', 0});

        while(!q.empty()) {
            // Mark current spot
            int f = q.front().f;
            int r = q.front().r;
            int d = q.front().dist;
            q.pop();
            v[f][r] = d;

            // Add new potential spots
            if(inrange(v, f-2, r-1)) {
                q.push({f-2, r-1, v[f][r]+1});
            }
            if(inrange(v, f-2, r+1)) {
                q.push({f-2, r+1, v[f][r]+1});
            }
            if(inrange(v, f+2, r-1)) {
                q.push({f+2, r-1, v[f][r]+1});
            }
            if(inrange(v, f+2, r+1)) {
                q.push({f+2, r+1, v[f][r]+1});
            }
            if(inrange(v, f-1, r-2)) {
                q.push({f-1, r-2, v[f][r]+1});
            }
            if(inrange(v, f-1, r+2)) {
                q.push({f-1, r+2, v[f][r]+1});
            }
            if(inrange(v, f+1, r-2)) {
                q.push({f+1, r-2, v[f][r]+1});
            }
            if(inrange(v, f+1, r+2)) {
                q.push({f+1, r+2, v[f][r]+1});
            }
        }

        // Find max
        int max = 0;
        for(auto i : v) {
            for(auto j : i) {
                if(j > max) {
                    max = j;
                }
            }
        }
        cout << max << " ";

        // Find all spots that correlate to the max
        vector<string> ans;
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(v[i][j] == max) {
                    string s;
                    s += (char)(i+'a');
                    s += (char)(j+'1');
                    ans.push_back(s);
                }
            }
        }

        // Sort answer by rank and file
        sort(ans.begin(), ans.end(), compare);
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}
