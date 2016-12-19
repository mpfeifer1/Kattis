#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    for(int i = 0; i < cases; i++) {
        int lines;
        cin >> lines;
        vector<string> types;
        vector<int> amount;
        for(int j = 0; j < lines; j++) {
            // Take in the clothing type
            string thing;
            string type;
            cin >> thing >> type;
            int loc = -1;
            // Check if that type already exists
            for(int i = 0; i < types.size(); i++) {
                if(types[i] == type) {
                    loc = i;
                }
            }
            // If it doesn't, add it
            if(loc == -1) {
                types.push_back(type);
                amount.push_back(1);
            }
            // If it does exist, add one
            else {
                amount[loc]++;
            }
        }

        int total = 1;
        for(auto n : amount) {
            total *= n + 1;
        }
        cout << total - 1 << endl;

    }
}
