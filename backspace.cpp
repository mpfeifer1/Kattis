#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    string ans;

    for(auto i : s) {
        if(i == '<') {
            ans.pop_back();
        }
        else {
            ans.push_back(i);
        }
    }

    cout << ans << endl;
}
