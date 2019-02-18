#include <bits/stdc++.h>

using namespace std;
#define uset unordered_set

struct race {
    vector<int> skills;
    int idx;
};

bool operator<(const race& r1, const race& r2) {
    return r1.skills.size() > r2.skills.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, p;
    cin >> n >> m >> p;

    // Stores each race and their skills
    vector<race> races;
    vector<int> numskills(m+1,n);
    for(int i = 1; i <= m; i++) {
        race r;
        int t; cin >> t;
        r.skills.resize(t);
        for(auto& i : r.skills) {
            cin >> i;
        }
        r.idx = i;
        races.push_back(r);
        numskills[i] = t;
    }

    // Maps each race to the characters w/ that race
    vector<vector<int>> characters(m+1);
    for(int i = 1; i <= p; i++) {
        int r; cin >> r;
        characters[r].push_back(i);
    }

    // Build the adjacency list of races
    vector<vector<int>> adj(m+1);
    vector<int> par_race(n+1,0);
    sort(races.begin(),races.end());
    for(auto& i : races) {
        int n1 = par_race[i.skills[0]];
        int n2 = i.idx;
        adj[n1].push_back(n2);
        for(auto& j : i.skills) {
            par_race[j] = i.idx;
        }
    }

    // Go down the tree
    // While team can be made, build it
    uset<int> team;
    team.insert(0);
    vector<vector<int>> teams;

    bool good = true;
    while(good) {
        // Count how many races we're out of
        queue<int> zeroin;
        for(auto& i : team) {
            if(characters[i].size() == 0) {
                zeroin.push(i);
            }
        }

        // If we have all races, build one of that team
        if(zeroin.size() == 0) {
            vector<int> currteam;
            for(auto& i : team) {
                currteam.push_back(characters[i].back());
                characters[i].pop_back();
            }
            teams.push_back(currteam);
        }

        // If not, advance any races we're out of
        // If there's no substitute for a race, quit
        else {
            while(!zeroin.empty()) {
                int curr = zeroin.front();
                zeroin.pop();
                team.erase(curr);
                int currskills = numskills[curr];
                for(auto& next : adj[curr]) {
                    team.insert(next);
                    currskills -= numskills[next];
                    if(characters[next].size() == 0) {
                        zeroin.push(next);
                    }
                }
                if(currskills != 0) {
                    good = false;
                }
            }
        }
    }

    cout << teams.size() << endl;
    for(auto& i : teams) {
        cout << i.size() << " ";
        for(auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
