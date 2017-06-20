#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct timestruct {
    int hours = 0;
    int minutes = 0;
    char c = 'a';
};

bool compare(timestruct t1, timestruct t2) {
    // Check AM PM
    if(t1.c < t2.c) {
        return true;
    }
    if(t1.c > t2.c) {
        return false;
    }

    int t1comb = t1.hours * 100 + t1.minutes;
    int t2comb = t2.hours * 100 + t2.minutes;

    return t1comb < t2comb;
}

int main() {
    int n;
    while(cin >> n && n != 0) {
        vector<timestruct> v;

        for(int i = 0; i < n; i++) {
            char trash1;
            string trash2;

            timestruct t;
            cin >> t.hours;
            cin >> trash1;
            cin >> t.minutes;
            cin >> t.c;
            cin >> trash2;

            if(t.hours == 12) {
                t.hours -= 12;
            }

            v.push_back(t);
        }

        sort(v.begin(), v.end(), compare);

        for(auto t : v) {
            if(t.hours == 0) {
                cout << 12;
            }
            else {
                cout << t.hours;
            }
            cout << ":";
            if(t.minutes < 10) {
                cout << "0";
            }
            cout << t.minutes;
            cout << ' ';
            cout << t.c;
            cout << ".m." << endl;
        }

        cout << endl;
    }
}
