#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Pairs: First index is operation,
// second is number
// 1: Less Than
// 2: Greater than
// 3: Divisible by

int main() {
    int n;
    while(cin >> n && n != 0) {
        vector<pair<int, int>> commands;

        for(int i = 0; i < n; i++) {
            string command, garbage;
            int temp;
            cin >> command >> garbage >> temp;

            int op;
            if(command == "less") {
                op = 1;
            }
            if(command == "greater") {
                op = 2;
            }
            if(command == "divisible") {
                op = 3;
            }

            commands.push_back({op, temp});
        }

        sort(commands.begin(), commands.end());

        if(commands[0].first != 1) {
            cout << "infinite" << endl;
            continue;
        }


        vector<bool> possible;
        possible.resize(commands[0].second, true);
        for(auto i : commands) {
            if(i.first == 1) {
                continue;
            }
            if(i.first == 2) {
                for(int j = 0; j < possible.size() && j <= i.second; j++) {
                    possible[j] = false;
                }
            }
            if(i.first == 3) {
                for(int j = 0; j < possible.size(); j++) {
                    if(j % i.second != 0) {
                        possible[j] = false;
                    }
                }
            }
        }

        bool printed = false;
        for(int i = 1; i < possible.size(); i++) {
            if(possible[i]) {
                printed = true;
                cout << i << " ";
            }
        }

        if(!printed) {
            cout << "none";
        }
        cout << endl;
    }
}
