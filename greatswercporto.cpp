#include <bits/stdc++.h>

using namespace std;

int total = 0;
int pos = 0;

// Set up storage
vector<char> all;
vector<bool> chosen(10, false);
vector<int> permutation;
unordered_set<char> firstletter;
unordered_set<char> seen;
unordered_map<char, int> cost1;
unordered_map<char, int> cost2;

void search() {
    if(permutation.size() == all.size()) {
        int total1 = 0;
        int total2 = 0;

        for(int i = 0; i < all.size(); i++) {
            total1 += cost1[all[i]] * permutation[i];
            total2 += cost2[all[i]] * permutation[i];
        }

        if(total1 == total2) {
            total++;
        }
    }
    else {
        for(int i = 0; i <= 9; i++) {
            if(chosen[i]) {
                continue;
            }
            if(i == 0 && firstletter.count(all[pos]) > 0) {
                continue;
            }
            pos++;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            permutation.pop_back();
            chosen[i] = false;
            pos--;
        }
    }
}

int main() {
    int n;
    cin >> n;

    // Read in addends
    for(int i = 0; i < n-1; i++) {
        string s;
        cin >> s;

        firstletter.insert(s.front());
        reverse(s.begin(), s.end());
        for(int j = 0; j < s.size(); j++) {
            cost1[s[j]] += pow(10, j);
        }

        for(auto j : s) {
            seen.insert(j);
        }
    }

    // Read in sum
    string s;
    cin >> s;
    firstletter.insert(s.front());
    reverse(s.begin(), s.end());
    for(int j = 0; j < s.size(); j++) {
        cost2[s[j]] += pow(10, j);
    }
    for(auto j : s) {
        seen.insert(j);
    }

    // Mark all as seen
    for(auto i : seen) {
        all.push_back(i);
    }

    // Search all permutations
    search();

    cout << total << endl;
}
