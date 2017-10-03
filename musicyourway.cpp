#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int index;

bool compare(vector<string> lhs, vector<string> rhs) {
    return lhs[index] < rhs[index];
}

int main() {
    string s;
    getline(cin, s);

    // Get a vector of all the categories
    vector<string> split;
    split.push_back("");
    for(auto i : s) {
        if(i == ' ') {
            split.push_back("");
        }
        else {
            split.back().push_back(i);
        }
    }

    // Take in all the songs
    int num_songs;
    cin >> num_songs;
    vector<vector<string>> v;
    for(int i = 0; i < num_songs; i++) {
        vector<string> song;
        for(int j = 0; j < split.size(); j++) {
            string temp;
            cin >> temp;
            song.push_back(temp);
        }
        v.push_back(song);
    }

    // Sort every time
    int num_queries;
    cin >> num_queries;
    for(int i = 0; i < num_queries; i++) {
        string query;
        cin >> query;

        // Sort on the index
        for(int i = 0; i < split.size(); i++) {
            if(split[i] == query) {
                index = i;
            }
        }
        stable_sort(v.begin(), v.end(), compare);

        // Print the list of songs
        cout << s << endl;
        for(auto song : v) {
            for(auto property : song) {
                cout << property << " ";
            }
            cout << endl;
        }

        if(i != num_queries - 1) {
            cout << endl;
        }
    }
}
