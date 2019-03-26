#include <bits/stdc++.h>

using namespace std;

int lcm(int a, int b) {
    return a / __gcd(a,b) * b;
}

pair<int,vector<int>> getratio(vector<pair<int,int>> v) {
    int top = v[0].first;
    for(auto i : v) {
        top = lcm(top,i.first);
    }

    vector<int> bot;
    for(auto i : v) {
        bot.push_back(i.second * (top / i.first));
    }

    return {top,bot};
}

void solve(vector<pair<int,int>>& v1, vector<pair<int,int>>& v2) {
    pair<int,vector<int>> r1 = getratio(v1);
    pair<int,vector<int>> r2 = getratio(v2);

    sort(r1.second.rbegin(),r1.second.rend());
    sort(r2.second.rbegin(),r2.second.rend());

    if(r1.first > 10000 || r2.first > 10000) return;

    if(r1.second[0] > r2.second[0]) {
        swap(r1,r2);
    }

    if(r2.second[0] % r1.second[0] != 0) return;
    int diff = r2.second[0] / r1.second[0];
    for(auto& i : r1.second) {
        i *= diff;
    }
    r1.first *= diff;

    if(r1.second == r2.second) {
        cout << r1.first << " " << r2.first << endl;
        for(auto i : r1.second) {
            cout << i << " ";
        }
        cout << endl;
        exit(0);
    }
}

int main() {
    vector<pair<int,int>> v;
    v.resize(12);
    char c;
    for(auto& i : v) {
        cin >> i.first >> c >> i.second;
    }

    // For each subset of 6 of the 12, do some processing
    for(int i = 0; i < (1<<12); i++) {
        if(__builtin_popcount(i) == 6) {
            vector<pair<int,int>> v1;
            vector<pair<int,int>> v2;

            for(int j = 0; j < 12; j++) {
                if(i & (1<<j)) {
                    v1.push_back(v[j]);
                }
                else {
                    v2.push_back(v[j]);
                }
            }

            solve(v1,v2);
        }
    }

    cout << "impossible" << endl;
}
