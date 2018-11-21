#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

int main() {
    int n;
    cin >> n;

    vector<int> s;

    for(int i = 0; i < n; i++) {
        ld d;
        cin >> d; d /= 440;
        while(d >= 2) d /= 2;
        while(d < 1) d *= 2;

        s.push_back(int(log2(d+.00001) * 12));
    }

    map<string, map<int,string>> m;
    m["G major"] = {{10,"G"}, {0,"A"}, {2,"B"}, {3,"C"}, {5,"D"}, {7,"E"}, {9,"F#"}};
    m["C major"] = {{3,"C"}, {5,"D"}, {7,"E"}, {8,"F"}, {10,"G"}, {0,"A"}, {2,"B"}};
    m["Eb major"] = {{6,"Eb"}, {8,"F"}, {10,"G"}, {11,"Ab"}, {1,"Bb"}, {3,"C"}, {5,"D"}};
    m["F# minor"] = {{9,"F#"}, {11,"G#"}, {0,"A"}, {2,"B"}, {4,"C#"}, {5,"D"}, {7,"E"}};
    m["G minor"] = {{10,"G"}, {0,"A"}, {1,"Bb"}, {3,"C"}, {5,"D"}, {6,"Eb"}, {8,"F"}};

    int keys = 0;
    string key = "";

    for(auto i : m) {
        bool works = true;
        for(auto j : s) {
            if(i.second.count(j) == 0) {
                works = false;
                break;
            }
        }
        if(works) {
            keys++;
            key = i.first;
        }
    }

    if(keys == 1) {
        cout << key << endl;
        for(auto i : s) {
            cout << m[key][i] << endl;
        }
    }
    else {
        cout << "cannot determine key" << endl;
    }
}
