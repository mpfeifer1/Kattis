#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

ll count(string& s) {
    ll ct = 0;
    for(auto& i : s) {
        if(i == '?') ct++;
    }
    return ct;
}

bool cmp(string& s1, string& s2) {
    return count(s1) < count(s2);
}

ll sz;
bool works(ll t, string& s) {
    string o = to_string(t);

    if(o.size() != sz) return false;
    if((s == "?" || s == "0") && o == "0") return true;
    if(s[0] == '0') return false;

    for(ll i = 0; i < s.size(); i++) {
        if(s[i] != o[i] && s[i] != '?') {
            return false;
        }
    }
    return true;
}

ll temp = 0;
void permute(vector<ll>& v, string& s, ll pos = 0) {
    if(pos == s.size()) {
        v.push_back(temp);
        return;
    }

    if(s[pos] == '?') {
        temp *= 10;
        ll i = 0;
        if(pos == 0 && s.size() > 1) i = 1;
        for(; i < 10; i++) {
            temp += i;
            permute(v,s,pos+1);
            temp -= i;
        }
        temp /= 10;
    }
    else {
        temp *= 10;
        temp += s[pos] - '0';
        permute(v,s,pos+1);
        temp -= s[pos] - '0';
        temp /= 10;
    }
}

int main() {
    vector<string> v(3);
    cin >> v[0] >> v[1] >> v[1] >> v[2] >> v[2];
    sort(v.begin(),v.end(),cmp);

    vector<ll> v1, v2;
    permute(v1,v[0]);
    permute(v2,v[1]);
    sz = v[2].size();

    ll ways = 0;
    for(auto& i : v1) {
        for(auto& j : v2) {
            if(works(i^j,v[2])) {
                ways++;
            }
        }
    }

    for(ll i = 0; i <= 2; i++) {
        if(v[i] != "0" && v[i].front() == '0') {
            ways = 0;
        }
    }

    cout << ways << endl;
}
