#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool strless(const string& lhs, const string& rhs) {
    if(lhs[0] == rhs[0]) {
        return lhs[1] < rhs[1];
    }
    else {
        return lhs[0] < rhs[0];
    }
}

int main() {
    int n;
    while(cin >> n && n != 0) {
        vector<string> v;

        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;

            v.push_back(s);
        }

        stable_sort(v.begin(), v.end(), strless);

        for(auto s : v) {
            cout << s << endl;
        }

        cout << endl;
    }
}
