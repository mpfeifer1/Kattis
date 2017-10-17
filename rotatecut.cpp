#include <iostream>
#include <string>
#include <deque>

using namespace std;

typedef long long ll;

int main() {
    ll cases;
    cin >> cases;
    while(cases--) {
        ll cuts;
        string s;
        cin >> cuts >> s;

        deque<char> word;
        for(auto i : s) {
            word.push_back(i);
        }

        for(int i = 0; i < cuts; i++) {
            ll toremove = word.size() / 4;
            if(toremove == 0) {
                break;
            }

            for(int j = 0; j < toremove; j++) {
                if(i % 2 == 0) {
                    word.pop_front();
                }
                else {
                    word.pop_back();
                }
            }
        }

        while(word.size() > 0) {
            cout << word.front();
            word.pop_front();
        }
        cout << endl;
    }
}
