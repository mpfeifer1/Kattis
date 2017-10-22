#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool calculate(vector<vector<bool>>& graph, vector<string> v) {
    if(v.size() <= 1) {
        return true;
    }

    // Grab all the unique elements in order in the first column
    vector<int> alphabet;
    for(auto i : v) {
        alphabet.push_back(i[0] - 'a');
    }
    auto it = unique(alphabet.begin(), alphabet.end());
    alphabet.resize(distance(alphabet.begin(), it));

    // Add them to the graph
    for(int i = 0; i < alphabet.size()-1; i++) {
        for(int j = i+1; j < alphabet.size(); j++) {
            int c1 = alphabet[j];
            int c2 = alphabet[i];
            graph[c1][c2] = true;
            if(graph[c2][c1]) {
                return false;
            }
        }
    }

    // Split the strings by first char, send them into the recursive call
    vector<vector<string>> split;
    vector<string> empty;
    split.push_back(empty);
    if(v[0].size() > 1) {
        split[split.size()-1].push_back(v[0]);
    }
    for(int i = 1; i < v.size(); i++) {
        if(v[i][0] != v[i-1][0]) {
            split.push_back(empty);
        }
        if(v[i].size() > 1) {
            split[split.size()-1].push_back(v[i]);
        }
    }

    for(auto& i : split) {
        for(auto& j : i) {
            j.erase(0, 1);
        }
    }

    for(auto i : split) {
        bool success = calculate(graph, i);
        if(!success) {
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
