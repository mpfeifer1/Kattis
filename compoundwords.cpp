#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    vector<string> v;
    vector<string> print;
    string s;
    while(cin >> s) {
        v.push_back(s);
    }
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            if(i != j) {
                string temp = v[i] + v[j];
                print.push_back(temp);
            }
        }
    }

    sort(print.begin(), print.end());

    string last = "";
    for(int i = 0; i < print.size(); i++) {
        if(last != print[i]) {
            cout << print[i] << endl;
            last = print[i];
        }
    }
}
