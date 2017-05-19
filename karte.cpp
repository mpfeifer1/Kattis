#include <iostream>
#include <string>
#include <vector>

using namespace std;

int left(vector<bool> v) {
    int cards = 13;

    for(auto b : v) {
        if(b) {
            cards--;
        }
    }

    return cards;
}

int main() {
    string s;
    cin >> s;

    vector<bool> p;
    vector<bool> k;
    vector<bool> h;
    vector<bool> t;

    p.resize(14, false);
    k.resize(14, false);
    h.resize(14, false);
    t.resize(14, false);

    bool duplicate = false;

    for(int i = 0; i < s.length(); i+=3) {
        char suit = s[i];
        int num = 10 * (s[i+1]-'0') + (s[i+2]-'0');

        if(suit == 'P') {
            if(p[num]) {
                duplicate = true;
                cout << "GRESKA" << endl;
                break;
            }
            else {
                p[num] = true;
            }
        }

        if(suit == 'K') {
            if(k[num]) {
                duplicate = true;
                cout << "GRESKA" << endl;
                break;
            }
            else {
                k[num] = true;
            }
        }

        if(suit == 'H') {
            if(h[num]) {
                duplicate = true;
                cout << "GRESKA" << endl;
                break;
            }
            else {
                h[num] = true;
            }
        }

        if(suit == 'T') {
            if(t[num]) {
                duplicate = true;
                cout << "GRESKA" << endl;
                break;
            }
            else {
                t[num] = true;
            }
        }
    }

    if(!duplicate) {
        cout << left(p) << " ";
        cout << left(k) << " ";
        cout << left(h) << " ";
        cout << left(t) << " ";
        cout << endl;
    }
}
