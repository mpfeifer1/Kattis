#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    string s;

    vector<string> names;
    unordered_map<string, int> votes;

    while(getline(cin, s)) {
        if(s == "***") {
            break;
        }
        if(votes.count(s) > 0) {
            votes.find(s)->second++;
        }
        else {
            names.push_back(s);
            votes.insert({s, 0});
        }
    }

    int maxIndex = 0;
    bool tie = false;

    for(int i = 1; i < names.size(); i++) {
        int currentVotes = votes.find(names[i])->second;
        int maxVotes = votes.find(names[maxIndex])->second;

        if(currentVotes == maxVotes) {
            tie = true;
        }

        if(currentVotes > maxVotes) {
            tie = false;
            maxIndex = i;
        }
    }

    if(tie) {
        cout << "Runoff!" << endl;
    }
    else {
        cout << names[maxIndex] << endl;
    }
}

