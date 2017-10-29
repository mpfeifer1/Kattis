#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> v;
    v.resize(28, vector<int>(28));

    for(int i = 0; i < 28; i++) {
        for(int j = i; j < 28; j++) {
            v[i][j] = min(j-i, (28-j) + i);
            v[j][i] = v[i][j];
        }
    }

    int n;
    cin >> n;
    cin.ignore();

    for(int i = 0; i < n; i++) {
        double total = 0;
        string s;
        getline(cin, s);

        for(int j = 1; j < s.size(); j++) {
            int spot1, spot2;
            spot1 = s[j-1] - 'A';
            spot2 = s[j] - 'A';

            if(s[j-1] == ' ') {
                spot1 = 26;
            }
            if(s[j-1] == '\'') {
                spot1 = 27;
            }
            if(s[j] == ' ') {
                spot2 = 26;
            }
            if(s[j] == '\'') {
                spot2 = 27;
            }

            total += v[spot1][spot2];
        }

        total *= M_PI * 60.0 / 28 / 15;
        total += s.length();
        cout << fixed;
        cout.precision(10);
        cout << total << endl;

    }

}
