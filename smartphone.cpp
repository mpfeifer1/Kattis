#include <bits/stdc++.h>

using namespace std;

int rewrite(string sZ, string suggZ) {
    deque<char> s, sugg;

    for(auto i : sZ) {
        s.push_back(i);
    }
    for(auto i : suggZ) {
        sugg.push_back(i);
    }

    while(s.size() > 0 && sugg.size() > 0 && s.front() == sugg.front()) {
        s.pop_front();
        sugg.pop_front();
    }
    return s.size() + sugg.size();
}

void solve() {
    string des;
    string wri;
    string s1, s2, s3;
    cin >> des >> wri >> s1 >> s2 >> s3;

    int op1 = 1+rewrite(des, s1);
    int op2 = 1+rewrite(des, s2);
    int op3 = 1+rewrite(des, s3);
    int op4 = rewrite(des, wri);

    cout << min({op1,op2,op3,op4}) << endl;
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
