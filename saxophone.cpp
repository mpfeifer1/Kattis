#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    cin.ignore();

    unordered_map<char, string> keys;
    keys['c'] = "0111001111";
    keys['d'] = "0111001110";
    keys['e'] = "0111001100";
    keys['f'] = "0111001000";
    keys['g'] = "0111000000";
    keys['a'] = "0110000000";
    keys['b'] = "0100000000";
    keys['C'] = "0010000000";
    keys['D'] = "1111001110";
    keys['E'] = "1111001100";
    keys['F'] = "1111001000";
    keys['G'] = "1111000000";
    keys['A'] = "1110000000";
    keys['B'] = "1100000000";

    for(int i = 0; i < cases; i++) {
        vector<int> count;
        count.resize(10, 0);

        string notes;
        getline(cin, notes);

        // If no notes
        if(notes.size() == 0) {
            // Print answer
            for(auto j : count) {
                cout << j << " ";
            }
            cout << endl;
            continue;
        }

        // Get first note
        string initial = keys[notes[0]];
        for(int i = 0; i < 10; i++) {
            if(initial[i] == '1') {
                count[i]++;
            }
        }

        // Get all following notes
        for(int j = 0; j < notes.size()-1; j++) {
            string s1, s2;
            s1 = keys[notes[j]];
            s2 = keys[notes[j+1]];

            for(int k = 0; k < 10; k++) {
                if(s1[k] == '0' && s2[k] == '1') {
                    count[k]++;
                }
            }
        }

        // Print answer
        for(auto j : count) {
            cout << j << " ";
        }
        cout << endl;
    }
}
