#include <bits/stdc++.h>

using namespace std;
typedef vector<vector<int>> card;
typedef set<int> win;

card getcard() {
    vector<vector<int>> v(5, vector<int>(5));
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> v[i][j];
        }
    }
    return v;
}

void getwins(vector<win>& wins, card c) {
    for(int i = 0; i < 5; i++) {
        set<int> s;
        for(int j = 0; j < 5; j++) {
            s.insert(c[i][j]);
        }
        wins.push_back(s);
    }
}

bool tie(vector<win>& wins, card c1, card c2) {
    // for each shared number bewteen c1 and c2, get the other numbers required to make them tie
    // if there's a win that contains all of those, it won't work

    map<int,int> ct;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            ct[c1[i][j]]++;
            ct[c2[i][j]]++;
        }
    }

    map<int, set<int>> othersneeded;
    for(auto i : c1) {
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) {
                if(j == k) continue;
                othersneeded[i[j]].insert(i[k]);
            }
        }
    }
    for(auto i : c2) {
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) {
                if(j == k) continue;
                othersneeded[i[j]].insert(i[k]);
            }
        }
    }

    for(auto i : ct) {
        if(i.second == 2) {

            int tienum = i.first;

            bool otherscanwin = false;
            for(auto winhere : wins) {
                int matches = 0;
                for(auto k : othersneeded[tienum]) {
                    if(winhere.count(k) > 0) matches++;
                }
                if(matches >= 5) otherscanwin = true;
            }

            if(!otherscanwin) return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<card> cards(n);
    for(auto& i : cards) {
        i = getcard();
    }

    vector<win> wins;
    for(auto i : cards) {
        getwins(wins, i);
    }

    bool printed = false;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(tie(wins, cards[i],cards[j])) {
                cout << i+1 << " " << j+1 << endl;
                printed = true;
                break;
            }
        }
        if(printed) break;
    }

    if(!printed) {
        cout << "no ties" << endl;
    }
}
