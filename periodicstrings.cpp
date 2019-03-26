#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


string s;

bool periodic(int k) {
    if(s.size()%k != 0) return false;
    vector<string> arr;
    for(int i = 0; i < s.size(); i += k) {
        arr.push_back(s.substr(i,k));
    }
    for(int i = 1; i < arr.size(); ++i) {
        string prev = arr[i-1];
        prev = prev.back() + prev;
        prev.pop_back();
        if(arr[i] != prev) return false;
    }
    return true;
}

int main() {
    cin >> s;
    for(int k = 1; k <= s.size(); ++k) {
        if(periodic(k)) {
            cout << k << '\n';
            return 0;
        }
    }
}
