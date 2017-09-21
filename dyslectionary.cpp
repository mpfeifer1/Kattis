#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void process(vector<string>& v) {
    // Find the max length for each string
    int maxlen = 0;
    for(auto i : v) {
        if(i.length() > maxlen) {
            maxlen = i.length();
        }
    }

    // Reverse each string, sort, flip them back
    for(auto& i : v) {
        reverse(i.begin(), i.end());
    }
    sort(v.begin(), v.end());
    for(auto& i : v) {
        reverse(i.begin(), i.end());
    }

    // Pad all strings with spaces
    for(auto& i : v) {
        string temp;
        temp.resize(maxlen - i.length(), ' ');
        temp += i;
        swap(i, temp);
    }

    // Print the strings
    for(auto i : v) {
        cout << i << endl;
    }
}

int main() {
    string s;
    vector<string> v;
    while(getline(cin, s)) {
        if(s == "") {
            process(v);

            cout << endl;
            v.clear();
            continue;
        }

        v.push_back(s);
    }
    process(v);
}
