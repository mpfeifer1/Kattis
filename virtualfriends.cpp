#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int find(vector<int>& d, int a) {
    if(d[a] < 0) {
        return a;
    }
    return d[a] = find(d, d[a]);
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);
    if(a == b) return;
    d[b] += d[a];
    d[a] = b;
}

int size(vector<int>& d, int a) {
    a = find(d, a);
    return -d[a];
}

void solve() {
    int n;
    cin >> n;

    vector<int> d;
    map<string,int> idx;

    for(int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        if(idx.count(s1) == 0) {
            idx[s1] = d.size();
            d.push_back(-1);
        }

        if(idx.count(s2) == 0) {
            idx[s2] = d.size();
            d.push_back(-1);
        }

        int v1 = idx[s1];
        int v2 = idx[s2];

        join(d, v1, v2);
        cout << size(d, v1) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int cases;
    cin >> cases;

    while(cases--) {
        solve();
    }

    return 0;
}

