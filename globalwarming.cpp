#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

// Define globals
int graph[210][210];
int disjoint[210];
ll infinity = (ll)1<<60;
ll best;
map<vector<bool>, ll> memo;



int find(int a) {
    if(disjoint[a] == -1) {
        return a;
    }
    int temp = find(disjoint[a]);

    disjoint[a] = temp;

    return temp;
}



void join(int a, int b) {
    int idxA = find(a);
    int idxB = find(b);

    if(idxA == idxB) {
        return;
    }

    disjoint[idxA] = idxB;
}



ll get_best(vector<int> & island, vector<bool> & used) {
    // If memoized, return that
    if(memo.count(used) != 0) {
        return memo[used];
    }

    // Find the first half of the pair
    int startIdx = -1;
    for(int i = 0; i < used.size(); i++) {
        if(!used[i]) {
            startIdx = i;
            break;
        }
    }

    // If no valid starts left, return
    if(startIdx == -1) {
        return 0;
    }
    used[startIdx] = true;
    ll localBest = infinity;

    // Recurse given each matching number
    for(int i = startIdx + 1; i < used.size(); i++) {
        if(!used[i]) {
            used[i] = true;
            ll temp;
            temp = graph[island[startIdx]][island[i]] + get_best(island, used);
            localBest = min(temp, localBest);
            used[i] = false;
        }
    }
    used[startIdx] = false;

    // Return the best found
    memo[used] = localBest;
    return localBest;
}

int main() {
    // Initialize the disjoint set to all 0's
    for(int i = 0; i < 210; i++) {
        disjoint[i] = - 1;
    }

    // Read in the students
    ll numStudents, numConnections;
    cin >> numStudents >> numConnections;

    // Read in the data
    for(ll i = 0; i <  numConnections; i++) {
        // Read in
        int studA, studB;
        ll dist;
        cin >> studA >> studB >> dist;

        // Make 0-based
        studA--;
        studB--;

        // Add to graph
        graph[studA][studB] = dist;
        graph[studB][studA] = dist;

        // Union together
        join(studA, studB);
    }

    // Create a map of all the 'student islands'
    map<int, vector<int> > islands;

    // Fill the islands
    for(int i = 0; i < numStudents; i++) {
        int parent = find(i);
        islands.emplace(parent, vector<int>());

        islands[parent].push_back(i);
    }

    // For each island, tell if it's impossible or solve
    ll total = 0;
    for(auto it : islands) {
        // Best so far is infinite
        best = infinity;
        memo.clear();

        // If odd number of students, quit
        if(it.second.size()% 2 == 1) {
            cout << "impossible" << endl;
            return 0;
        }

        // Solve the island, add to total
        vector<bool> used(it.second.size(),false);
        total += get_best(it.second, used);

    }
    cout << total << endl;

}

