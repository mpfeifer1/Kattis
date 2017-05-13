#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> v;
    v.resize(26, 0);

    for(auto c : s) {
        v[c-'a']++;
    }

    int odds = 0;

    for(auto i : v) {
        if(i % 2 == 1) {
            odds++;
        }
    }

    int result = odds - 1;

    if(result < 0) {
        result = 0;
    }

    cout << result << endl;
}
