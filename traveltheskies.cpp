#include <bits/stdc++.h>

using namespace std;

struct flight {
    int n1;
    int n2;
    int cap;
};

int main() {
    int k, n, m;
    cin >> k >> n >> m;

    // Number of people currently in this airport
    vector<int> people(k, 0);
    // Map of day to flights happening
    map<int, vector<flight>> flights;
    // Map of day to people arriving
    map<int,vector<pair<int,int>>> additional;

    // Read in all of the flights
    for(int i = 0; i < m; i++) {
        int d;
        flight f;
        cin >> f.n1 >> f.n2 >> d >> f.cap;
        f.n1--; f.n2--; d--;
        flights[d].push_back(f);
    }

    // Read in all of the peoples' arrivals
    for(int i = 0; i < k*n; i++) {
        int d, n1, cap;
        cin >> n1 >> d >> cap;
        n1--; d--;
        additional[d].push_back({n1,cap});
    }

    // Simulate each day
    bool works = true;
    for(int i = 0; i < n; i++) {
        // Add new arrivals
        for(auto j : additional[i]) {
            people[j.first] += j.second;
        }

        // Remove any people flying out
        for(auto j : flights[i]) {
            people[j.n1] -= j.cap;
            if(people[j.n1] < 0) {
                works = false;
                break;
            }
        }

        // If it doesn't work, quit early
        if(!works) break;

        // Add people flying in
        for(auto j : flights[i]) {
            people[j.n2] += j.cap;
        }
    }

    // Print answer
    if(works) cout << "optimal" << endl;
    else cout << "suboptimal" << endl;
}
