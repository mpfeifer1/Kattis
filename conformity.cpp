#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int students;
    cin >> students;

    unordered_map<string, int> combinations;

    for(int i = 0; i < students; i++) {
        vector<string> v;
        for(int j = 0; j < 5; j++) {
            string s;
            cin >> s;
            v.push_back(s);
        }

        sort(v.begin(), v.end());
        string s;
        for(auto i : v) {
            s += i;
        }

        combinations[s]++;
    }

    int m = 0;
    for(auto i : combinations) {
        m = max(m, i.second);
    }

    int total = 0;
    for(auto i : combinations) {
        if(i.second == m) {
            total += i.second;
        }
    }

    cout << total << endl;
}
