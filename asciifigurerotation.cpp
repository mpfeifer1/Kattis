#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    bool first = true;
    while(cin >> n && n != 0) {
        // If not the first time, add a space
        if(!first) {
            cout << endl;
        }
        else {
            first = false;
        }

        // Take in data
        cin.ignore();
        vector<string> v;
        for(int i = 0; i < n; i++) {
            string temp;
            getline(cin, temp);
            v.push_back(temp);
        }

        // Pad strings
        int maxlen = 0;
        for(auto& i : v) {
            int temp = i.length();
            maxlen = max(maxlen, temp);
        }
        for(auto& i : v) {
            i.resize(maxlen, ' ');
        }

        // Create new array
        vector<string> rotated;
        rotated.resize(maxlen);
        for(auto& i : rotated) {
            i.resize(n, ' ');
        }

        // Rotate
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < maxlen; j++) {
                rotated[j][i] = v[i][j];
            }
        }

        // Replace | and -
        for(auto& i : rotated) {
            for(auto& c : i) {
                if(c == '|') {
                    c = '-';
                }
                else if(c == '-') {
                    c = '|';
                }
            }
        }

        // Mirror image to be correct
        for(auto& i : rotated) {
            reverse(i.begin(), i.end());
        }

        // Strip ending spaces
        for(auto& i : rotated) {
            while(i[i.size()-1] == ' ') {
                i.pop_back();
            }
        }

        // Print
        for(auto& i : rotated) {
            cout << i << endl;
        }
    }
}
