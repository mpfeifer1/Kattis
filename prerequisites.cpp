#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while(cin >> n && n != 0 && cin >> m) {
        unordered_set<string> taken;
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            taken.insert(s);
        }

        bool works = true;
        for(int i = 0; i < m; i++) {
            int count, needed;
            cin >> count >> needed;

            int have = 0;
            for(int j = 0; j < count; j++) {
                string s;
                cin >> s;
                if(taken.count(s) > 0) {
                    have++;
                }
            }

            if(have < needed) {
                works = false;
            }
        }

        if(works) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
}
