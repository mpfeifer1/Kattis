#include <iostream>
#include <string>
#include <vector>

using namespace std;

void process(vector<string>& v) {
    vector<pair<int, int>> locations(62);

    int size = 0;
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            if(isdigit(v[i][j])) {
                size++;
                locations[v[i][j]-'0'] = {i,j};
            }
            if(isalpha(v[i][j])) {
                size++;
                if(islower(v[i][j])) {
                    locations[v[i][j]-'a'+10] = {i,j};
                }
                else {
                    locations[v[i][j]-'A'+36] = {i,j};
                }
            }
        }
    }

    for(int i = 1; i < size; i++) {
        pair<int, int> p1 = locations[i-1];
        pair<int, int> p2 = locations[i];

        // HORIZONTAL
        if(p1.first == p2.first) {
            int j = p1.first;

            // BACKWARD
            if(p1.second > p2.second) {
                for(int i = p1.second-1; i > p2.second; i--) {
                    if(v[j][i] == '|') {
                        v[j][i] = '+';
                    }
                    if(v[j][i] == '.') {
                        v[j][i] = '-';
                    }
                }
            }

            // FOREWARD
            else {
                for(int i = p1.second+1; i < p2.second; i++) {
                    if(v[j][i] == '|') {
                        v[j][i] = '+';
                    }
                    if(v[j][i] == '.') {
                        v[j][i] = '-';
                    }
                }
            }
        }

        // VERTICAL
        else {
            int j = p1.second;
            // UP
            if(p1.first > p2.first) {
                for(int i = p1.first-1; i > p2.first; i--) {
                    if(v[i][j] == '-') {
                        v[i][j] = '+';
                    }
                    if(v[i][j] == '.') {
                        v[i][j] = '|';
                    }
                }
            }

            // DOWN
            else {
                for(int i = p1.first+1; i < p2.first; i++) {
                    if(v[i][j] == '-') {
                        v[i][j] = '+';
                    }
                    if(v[i][j] == '.') {
                        v[i][j] = '|';
                    }
                }
            }
        }
    }

    // Print array
    for(auto s : v) {
        cout << s << endl;
    }

}

int main() {
    vector<string> v;
    string s;
    while(getline(cin, s)) {
        if(s == "") {
            process(v);
            v.clear();
            cout << endl;
        }
        else {
            v.push_back(s);
        }
    }
    process(v);
}
