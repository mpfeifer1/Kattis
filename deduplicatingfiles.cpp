#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

int sum(int n) {
    int total = 0;
    for(int i = 0; i <= n; i++) {
        total += i;
    }
    return total;
}

int getcollisions(unordered_map<int, unordered_map<string, int>> vals) {
    int total = 0;

    // For each hash that landed here
    for(auto i : vals) {
        // Get the count of each different string here
        vector<int> counts;
        for(auto j : i.second) {
            counts.push_back(j.second);
        }

        // Calculate the total collisions
        for(int j = 0; j < counts.size()-1; j++) {
            for(int k = j+1; k < counts.size(); k++) {
                total += counts[j] * counts[k];
            }
        }
    }

    return total;
}

int main() {
    int n;
    while(cin >> n && n != 0) {
        unordered_set<string> s;
        unordered_map<int, unordered_map<string, int>> vals;

        cin.ignore();
        for(int i = 0; i < n; i++) {
            // Read in sentence, add to set
            string sentence;
            getline(cin, sentence);
            s.insert(sentence);

            // Calculate hash, add it to list of hashes
            int hash = 0;
            for(auto c : sentence) {
                hash ^= c;
            }
            vals[hash][sentence]++;
        }

        int c = getcollisions(vals);
        cout << s.size() << " " << c << endl;
    }
}
