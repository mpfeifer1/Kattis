#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int dist(string& a, string& b) {
    int total = 0;
    vector<int> c(26);
    vector<int> d(26);

    for(auto& i : a) {
        c[i-'A']++;
    }
    for(auto& i : b) {
        d[i-'A']++;
    }

    for(int i = 0; i < 26; i++) {
        if(c[i] == 1 && d[i] == 1) {
            total++;
        }
    }

    return total;
}

int solve(vector<vector<int>>& perm, vector<int>& v) {
    int total = 0;
    for(int i = 1; i < v.size(); i++) {
        total += perm[v[i]][v[i-1]];
    }
    return total;
}

int main() {
    int n;
    cin >> n;

    vector<string> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    vector<vector<int>> distance;
    distance.resize(n, vector<int>(n));

    for(int i = 0; i < v.size(); i++) {
        for(int j = i+1; j < v.size(); j++) {
            distance[i][j] = dist(v[i], v[j]);
            distance[j][i] = distance[i][j];
        }
    }

    vector<int> perm(n);
    for(int i = 0; i < perm.size(); i++) {
        perm[i] = i;
    }

    int best = 1000;
    do {
        best = min(best, solve(distance, perm));
    } while(next_permutation(perm.begin(), perm.end()));

    cout << best << endl;
}
