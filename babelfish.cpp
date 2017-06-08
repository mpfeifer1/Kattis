#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line;
    unordered_map<string, string> words;
    while(getline(cin, line) && line != "") {
        string english, foreign;
        int index = line.find(' ');
        english = line.substr(0, index);
        foreign = line.substr(index+1, line.size()-1);

        words.insert({foreign, english});
    }

    while(getline(cin, line)) {
        if(words.count(line) > 0) {
            cout << words.find(line)->second << endl;
        }
        else {
            cout << "eh" << endl;
        }
    }
}
