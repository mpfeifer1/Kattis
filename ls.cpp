#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void print(deque<char> word) {
    for(auto i : word) {
        cout << i;
    }
    cout << endl;
}

void str_to_deque(string& s, deque<char>& d) {
    for(auto i : s) {
        d.push_back(i);
    }
}

void deque_to_str(string& s, deque<char>& d) {
    for(auto i : d) {
        s.push_back(i);
    }
}

bool solve(deque<char> pattern, deque<char> word) {
    // Strip beginning and end of extra chars
    while(!pattern.empty() && !word.empty() && pattern.front() == word.front()) {
        pattern.pop_front();
        word.pop_front();
    }
    while(!pattern.empty() && !word.empty() && pattern.back() == word.back()) {
        pattern.pop_back();
        word.pop_back();
    }

    // Return true if there are no stars and it worked
    if(pattern.empty() && word.empty()) {
        return true;
    }

    // If the pattern is empty and the word is not, it failed
    if(pattern.empty()) {
        return false;
    }

    // If there's no word, check that the pattern is all stars
    if(word.empty()) {
        bool all_stars = true;
        for(auto i : pattern) {
            if(i != '*') {
                all_stars = false;
            }
        }

        return all_stars;
    }

    // Debugging print
    //print(pattern);
    //print(word);

    // Check if the end values don't match
    if(pattern.front() != '*' || pattern.back() != '*') {
        return false;
    }

    // Build an array of patterns to find in the string
    vector<string> v_temp;
    for(auto i : pattern) {
        if(i == '*') {
            v_temp.push_back("");
        }
        else {
            v_temp[v_temp.size()-1].push_back(i);
        }
    }

    // Remove empty strings
    vector<string> v;
    for(auto i : v_temp) {
        if(i != "") {
            v.push_back(i);
        }
    }

    // Convert the word to a string
    string s = "";
    deque_to_str(s, word);

    // Check that all the search patterns exist
    int start = 0;
    for(auto i : v) {
        // If we're going to overstep, quit
        if(start >= s.size()) {
            return false;
        }

        // Find the next match
        int loc = s.find(i, start);

        // If no match, quit
        if(loc == -1) {
            return false;
        }

        // This is the new starting spot
        start = loc + i.size();
    }

    return true;
}

int main() {
    // Read in pattern
    string p;
    cin >> p;

    // Convert pattern
    deque<char> pattern;
    str_to_deque(p, pattern);

    // Test each word
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        // Read in word
        string temp;
        cin >> temp;
        deque<char> word;
        str_to_deque(temp, word);

        // If it works, print it
        if(solve(pattern, word)) {
            print(word);
        }
    }
}
