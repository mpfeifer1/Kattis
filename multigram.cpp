#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    // For each possible size
    for(int i = 1; i <= s.size()/2; i++) {
        // If not divisible, continue
        if(s.size() % i != 0) {
            continue;
        }

        vector<vector<int>> counts;
        counts.resize(s.size() / i, vector<int>(26));
        int strings = counts.size();

        for(int j = 0; j < s.size(); j++) {
            int currval = s[j] - 'a';
            counts[j/i][currval]++;
        }

        /*
        for(auto c : counts) {
            for(auto n : c) {
                cout << n <<" ";
            }
            cout << endl;
        }
        */

        vector<int> c1 = counts[0];
        bool works = true;
        for(int j = 1; j < strings; j++) {
            for(int k = 0; k < 26; k++) {
                if(c1[k] != counts[j][k]) {
                    works = false;
                }
            }
        }

        if(works) {
            for(int j = 0; j < i; j++) {
                cout << s[j];
            }
            cout << endl;
            return 0;
        }
    }

    cout << "-1" << endl;
}
