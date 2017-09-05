#include <unordered_map>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Determines if a string is only digits
bool isnumber(string s) {
    bool number = true;
    for(auto c : s) {
        number &= isdigit(c);
    }
    return number;
}

int main() {
    string line;

    // Set all vars to 0 by default
    unordered_map<string, int> vars;
    unordered_map<string, bool> vars_used;

    // For each line
    while(getline(cin, line) && line != "0") {

        // Split it by spaces
        stringstream ss(line);
        vector<string> words;
        string word;

        // Check if assignment or addition operation
        bool assignment = false;
        bool addition = false;
        while(ss >> word) {
            if(word == "=") {
                assignment = true;
            }
            if(word == "+") {
                addition = true;
            }
            words.push_back(word);
        }

        // Set the assignment
        if(assignment) {
            vars[words[0]] = stoi(words[2]);
            vars_used[words[0]] = true;
        }

        bool simplified = false;

        // Add the variables together
        if(addition) {
            // Set up output for later
            vector<string> addlater;
            int total = 0;

            // For each word
            for(int i = 0; i < words.size(); i+=2) {
                // If it is an int, add it
                if(isnumber(words[i])) {
                    total += stoi(words[i]);
                    simplified = true;
                }

                // If a word
                else {
                    // If it's defined, add it
                    if(vars_used[words[i]]) {
                        total += vars[words[i]];
                        simplified = true;
                    }

                    // Otherwise add it later
                    else {
                        addlater.push_back(words[i]);
                    }
                }
            }

            // If it has been simplified, print the total and the words
            if(simplified) {
                cout << total;
                for(auto w : addlater) {
                    cout << " + " << w;
                }
                cout << endl;
            }

            // Otherwise just print the words
            else {
                cout << addlater[0];
                addlater.erase(addlater.begin());
                for(auto w : addlater) {
                    cout << " + " << w;
                }
                cout << endl;
            }

        }
    }
}
