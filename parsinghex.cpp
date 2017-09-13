#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

bool ishex(char c) {
    if(c == 'x' || c == 'X') {
        return true;
    }
    if(c >= 'A' && c <= 'F') {
        return true;
    }
    if(c >= 'a' && c <= 'f') {
        return true;
    }
    if(c >= '0' && c <= '9') {
        return true;
    }

    return false;
}

string fix(string& s) {
    string temp;
    for(int i = 0; i < s.length(); i++) {
        if(!ishex(s[i])) {
            break;
        }
        temp.push_back(s[i]);
    }
    return temp;
}

vector<string> split(string& s) {
    vector<string> v;
    string temp;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '0' && tolower(s[i+1]) == 'x') {
            v.push_back(temp);
            temp.clear();
        }
        temp.push_back(s[i]);
    }
    v.push_back(temp);

    return v;
}

bool isvalid(string& s) {
    if(s.size() < 3) {
        return false;
    }
    if(s[0] != '0') {
        return false;
    }
    if(tolower(s[1]) != 'x') {
        return false;
    }

    return true;
}

int main() {
    string s;
    while(cin >> s) {
        //cout << "IN" << s << endl;
        vector<string> hex = split(s);
        for(auto i : hex) {
            i = fix(i);
            if(isvalid(i)) {
                cout << i << " ";
                cout << (int)strtol(i.c_str(), 0, 16) << endl;
            }
        }
    }
}
