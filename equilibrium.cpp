#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<string> split(string s) {
    vector<string> v {""};
    for(auto i : s) {
        if(i == '[') {
            v.push_back("[");
            v.push_back("");
        }
        else if(i == ']') {
            v.push_back("]");
            v.push_back("");
        }
        else if(i == ',') {
            v.push_back("");
        }
        else {
            v.back().push_back(i);
        }
    }
    return v;
}

void solve() {
    string s;
    cin >> s;

    int d = 0;

    map<ll,int> count;

    vector<string> tokens = split(s);
    int nums = 0;

    for(auto i : tokens) {
        if(i == "[") {
            d++;
        }
        else if(i == "]") {
            d--;
        }
        else if(i == "") {
        }
        else {
            ll val = stoll(i);
            count[val << d]++;
            nums++;
        }
    }

    int most = 0;
    for(auto i : count) {
        most = max(most, i.second);
    }

    cout << (nums - most) << endl;
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
