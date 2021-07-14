#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool addrules(vector<pair<int,int>>& rules, string& s1, string& s2) {
    for(int i = 0; i < max(s1.size(), s2.size()); i++) {
        if(i >= s1.size()) {
            return true;
        }
        if(i >= s2.size()) {
            return false;
        }
        if(s1[i] != s2[i]) {
            rules.push_back({s1[i]-'a', s2[i]-'a'});
            return true;
        }
    }
    return true;
}

bool calculate(vector<vector<bool>>& graph, vector<string>& v) {

    vector<pair<int,int>> rules;

    for(int i = 0; i < v.size()-1; i++) {
        if(!addrules(rules, v[i], v[i+1])) {
            return false;
        }
    }

    // Add them to the graph
    for(auto i : rules) {
        graph[i.second][i.first] = true;
        if(graph[i.first][i.second]) {
            return false;
        }
    }

    return true;
}

int main() {
    char l;
    int n;
    cin >> l >> n;
    int size = l - 'a' + 1;

    vector<string> v(n);

    for(auto& i : v) {
        cin >> i;
    }

    vector<vector<bool>> graph;
    graph.resize(size, vector<bool>(size, false));

    if(!calculate(graph, v)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    /*
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    */

    unordered_set<int> skip;
    vector<char> output;
    for(int i = 0; i < size; i++) {
        vector<int> zerocol;

        // Count all the zero rows
        for(int j = 0; j < size; j++) {
            // If this letter needs to be skipped, skip it
            if(skip.count(j) > 0) {
                continue;
            }

            // Check if this col is all zeros
            bool allzero = true;
            for(int k = 0; k < size; k++) {
                if(graph[j][k] == 1) {
                    allzero = false;
                }
            }

            // If it is, add it to the list
            if(allzero) {
                zerocol.push_back(j);
                if(zerocol.size() > 1) {
                    cout << "AMBIGUOUS" << endl;
                    return 0;
                }
            }
        }

        if(zerocol.size() == 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        else {
            output.push_back(zerocol[0] + 'a');
            skip.insert(zerocol[0]);
            for(int i = 0; i < size; i++) {
                graph[i][zerocol[0]] = 0;
            }
        }
    }

    for(auto i : output) {
        cout << i;
    }
    cout << endl;
}
