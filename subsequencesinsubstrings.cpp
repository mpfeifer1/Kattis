#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    string s, t;
    cin >> s >> t;
    vector<vector<int>> indexes(26);
    for(int i = 0; i < s.size(); ++i) {
        indexes[s[i]-'a'].push_back(i);
    }
    ll res = 0;
    for(int i = 0; i < s.size(); ++i) {
        int pos = i;
        bool possible = true;
        char prevLet = '$';
        for(int j = (int)t.size()-1; j >= 0; --j) {
            auto &arr = indexes[t[j]-'a'];
            auto it = upper_bound(arr.begin(), arr.end(), pos);
            if(it == arr.begin()) {
                possible = false;
                break;
            }
            --it;
            if(prevLet == t[j]) {
                if(it == arr.begin()) {
                    possible = false;
                    break;
                }
                --it;
            }
            pos = *it;

            prevLet = t[j];
        }
        if(possible) {
            res += pos+1;
        }
    }
    cout << res << '\n';
}
