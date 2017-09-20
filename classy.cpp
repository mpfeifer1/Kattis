#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void parse(string rank, string name, string& parsedRank) {
    for(int i = 0; i < rank.length(); i++) {
        if(rank[i] == 'u') {
            parsedRank += 'a';
        }
        if(rank[i] == 'm') {
            parsedRank += 'b';
        }
        if(rank[i] == 'o') {
            parsedRank += 'c';
        }
    }

    int l = parsedRank.length();
    for(int j = 0; j < l/2; j++) {
        swap(parsedRank[j], parsedRank[l-j-1]);
    }

    while(l < 10) {
        l++;
        parsedRank += 'b';
    }

    parsedRank += ' ';
    parsedRank += name;
    parsedRank.pop_back();
}

void print(vector<string> names) {
    for(int i = 0; i < names.size(); i++) {
        bool space = false;
        for(int j = 0; j < names[i].size(); j++) {
            if(space) {
                cout << names[i][j];
            }
            else if(names[i][j] == ' ') {
                space = true;
            }
        }
        cout << endl;
    }
    cout << "==============================" << endl;
}

int main() {
    int cases = 0, nameNum = 0;

    cin >> cases;
    for(int i = 0; i < cases; i++) {
        cin >> nameNum;
        vector<string> names;
        for(int j = 0; j < nameNum; j++) {
            string name, rank, parsedRank = "", garbage;
            cin >> name >> rank >> garbage;
            parse(rank, name, parsedRank);
            names.push_back(parsedRank);
        }
        sort(names.begin(), names.end());
        print(names);
    }
}
