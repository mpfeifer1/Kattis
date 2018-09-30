#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    int c = 0;
    vector<int> row(m);
    for(int i = n-1; i >= 0; i--) {
        map<pair<int,char>, int> thing;
        for(int j = 0; j < m; j++) {
            if(thing.count({row[j],v[i][j]}) > 0) {
                row[j] = thing[{row[j],v[i][j]}];
            }
            else {
                c++;
                thing[{row[j],v[i][j]}] = c;
                row[j] = c;
            }
        }

        if(thing.size() == m) {
            cout << i << endl;
            return 0;
        }
    }

    cout << 0 << endl;
}
