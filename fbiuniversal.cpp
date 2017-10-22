#include <unordered_map>
#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    unordered_map<char, ll> convert;
    convert['0'] = 0;
    convert['1'] = 1;
    convert['2'] = 2;
    convert['3'] = 3;
    convert['4'] = 4;
    convert['5'] = 5;
    convert['6'] = 6;
    convert['7'] = 7;
    convert['8'] = 8;
    convert['9'] = 9;
    convert['A'] = 10;
    convert['C'] = 11;
    convert['D'] = 12;
    convert['E'] = 13;
    convert['F'] = 14;
    convert['H'] = 15;
    convert['J'] = 16;
    convert['K'] = 17;
    convert['L'] = 18;
    convert['M'] = 19;
    convert['N'] = 20;
    convert['P'] = 21;
    convert['R'] = 22;
    convert['T'] = 23;
    convert['V'] = 24;
    convert['W'] = 25;
    convert['X'] = 26;

    convert['B'] = 8;
    convert['G'] = 11;
    convert['I'] = 1;
    convert['O'] = 0;
    convert['Q'] = 0;
    convert['S'] = 5;
    convert['U'] = 24;
    convert['Y'] = 24;
    convert['Z'] = 2;

    for(int i = 0; i < n; i++) {
        ll current;
        string s;
        cin >> current >> s;
        cout << current << " ";

        ll total = 0;
        total += 2 * convert[s[0]];
        total += 4 * convert[s[1]];
        total += 5 * convert[s[2]];
        total += 7 * convert[s[3]];
        total += 8 * convert[s[4]];
        total += 10 * convert[s[5]];
        total += 11 * convert[s[6]];
        total += 13 * convert[s[7]];

        total %= 27;

        if(total == convert[s[8]]) {
            ll sum = 0;
            for(int j = 0; j < 8; j++) {
                sum += pow(27, 7-j) * convert[s[j]];
            }
            cout << sum << endl;
        }
        else {
            cout << "Invalid" << endl;
        }
    }
}
