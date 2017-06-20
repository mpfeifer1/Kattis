#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<int> v;
    v.resize(26, 0);

    string s;
    cin >> s;

    for(auto c : s) {
        v[c-'a']++;
    }

    sort(v.rbegin(), v.rend());

    cout << s.size() - (v[0] + v[1]) << endl;
}
