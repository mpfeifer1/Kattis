#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

string lastWord(string s) {
    int index = s.find_last_of(' ') + 1;

    string last = s.substr(index);

    for(auto &c : last) {
        c = tolower(c);
    }

    return last;
}

int main() {
    int n;
    int i = 1;
    while(cin >> n && n != 0) {
        multiset<string> animals;
        vector<string> names;

        cin.ignore();
        for(int i = 0; i < n; i++) {
            string name;
            getline(cin, name);
            name = lastWord(name);

            if(animals.count(name) == 0) {
                names.push_back(name);
            }
            animals.insert(name);
        }

        sort(names.begin(), names.end());

        cout << "List " << i << ":" << endl;
        for(auto name : names) {
            cout << name << " | " << animals.count(name) << endl;
        }

        i++;
    }
}
