#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int>& p1, pair<int,int>& p2) {
    return p1.second < p2.second;
}

void process(vector<string>& dict, string& s) {
    vector<pair<int,int>> v;

    for(auto i : dict) {
        auto pos = s.find(i);
        while(pos != -1) {
            v.push_back({pos, pos+i.size()-1});
            pos++;
            pos = s.find(i,pos);
        }
    }

    sort(v.begin(), v.end(), cmp);

    int end = -1;
    int ct = 0;
    for(auto i : v) {
        if(i.first > end) {
            end = i.second;
            ct++;
        }
    }

    cout << ct << endl;
}

int main() {
    vector<string> dict;
    string s;
    while(cin >> s && s != "#") {
        dict.push_back(s);
    }

    string big;
    string t;
    while(cin >> t && t != "#") {
        big += t;
        if(big.back() == '|') {
            process(dict, big);
            big = "";
        }
    }
}
