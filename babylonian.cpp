#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    ll cases;
    cin >> cases;
    while(cases--) {
        vector<ll> v;
        string s;
        cin >> s;

        string actual;
        for(auto c : s) {
            if(c == ',') {
                actual.push_back(',');
                actual.push_back('0');
            }
            else {
                actual.push_back(c);
            }
        }

        vector<string> split;
        split.push_back("");
        for(auto c : actual) {
            if(c == ',') {
                split.push_back("");
            }
            else {
                split[split.size()-1].push_back(c);
            }
        }

        ll total = 0;
        for(ll i = 0; i < split.size(); i++) {
            string temp = split[split.size()-i-1];
            total += pow(60, i) * stoi(temp);
        }
        cout << total << endl;
    }
}
