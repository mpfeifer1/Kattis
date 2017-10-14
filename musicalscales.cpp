#include <iostream>
#include <vector>

using namespace std;

int tonum(string note) {
    if(note == "A") {
        return 0;
    }
    if(note == "A#") {
        return 1;
    }
    if(note == "B") {
        return 2;
    }
    if(note == "C") {
        return 3;
    }
    if(note == "C#") {
        return 4;
    }
    if(note == "D") {
        return 5;
    }
    if(note == "D#") {
        return 6;
    }
    if(note == "E") {
        return 7;
    }
    if(note == "F") {
        return 8;
    }
    if(note == "F#") {
        return 9;
    }
    if(note == "G") {
        return 10;
    }
    if(note == "G#") {
        return 11;
    }
}

string tonote(int n) {
    switch(n) {
        case 0:
            return "A";
        case 1:
            return "A#";
        case 2:
            return "B";
        case 3:
            return "C";
        case 4:
            return "C#";
        case 5:
            return "D";
        case 6:
            return "D#";
        case 7:
            return "E";
        case 8:
            return "F";
        case 9:
            return "F#";
        case 10:
            return "G";
        case 11:
            return "G#";
    }
}

bool inscale(vector<bool> ournotes, vector<int> scale) {
    bool works = true;
    for(int i = 0; i < ournotes.size(); i++) {

        bool inthisscale = false;
        for(int j = 0; j < scale.size(); j++) {
            if(scale[j] == i) {
                inthisscale = true;
            }
        }

        if(ournotes[i] && !inthisscale) {
            works = false;
        }
    }
    return works;
}

int main() {
    int notes;
    cin >> notes;

    vector<vector<int>> scales = {
    {0,2,4,5,7,9,11},
    {1,3,5,6,8,10,0},
    {2,4,6,7,9,11,1},
    {3,5,7,8,10,0,2},
    {4,6,8,9,11,1,3},
    {5,7,9,10,0,2,4},
    {6,8,10,11,1,3,5},
    {7,9,11,0,2,4,6},
    {8,10,0,1,3,5,7},
    {9,11,1,2,4,6,8},
    {10,0,2,3,5,7,9},
    {11,1,3,4,6,8,10}};


    vector<bool> ournotes(12, false);
    for(int i = 0; i < notes; i++) {
        string note;
        cin >> note;
        ournotes[tonum(note)] = true;
    }

    bool printed = false;
    for(int i = 0; i < scales.size(); i++) {
        if(inscale(ournotes, scales[i])) {
            printed = true;
            cout << tonote(i) << " ";
        }
    }

    if(!printed) {
        cout << "none";
    }
    cout << endl;
}

