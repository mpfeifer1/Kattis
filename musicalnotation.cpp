#include <iostream>
#include <vector>
#include <string>

using namespace std;

void addspace(vector<string>& staff) {
    staff[0].push_back(' ');
    staff[1].push_back('-');
    staff[2].push_back(' ');
    staff[3].push_back('-');
    staff[4].push_back(' ');
    staff[5].push_back('-');
    staff[6].push_back(' ');
    staff[7].push_back('-');
    staff[8].push_back(' ');
    staff[9].push_back('-');
    staff[10].push_back(' ');
    staff[11].push_back(' ');
    staff[12].push_back(' ');
    staff[13].push_back('-');
}

void addnote(vector<string>& staff, char note) {
        if(note == 'G') {
            staff[0][staff[0].size()-1] = '*';
        }
        if(note == 'F') {
            staff[1][staff[0].size()-1] = '*';
        }
        if(note == 'E') {
            staff[2][staff[0].size()-1] = '*';
        }
        if(note == 'D') {
            staff[3][staff[0].size()-1] = '*';
        }
        if(note == 'C') {
            staff[4][staff[0].size()-1] = '*';
        }
        if(note == 'B') {
            staff[5][staff[0].size()-1] = '*';
        }
        if(note == 'A') {
            staff[6][staff[0].size()-1] = '*';
        }
        if(note == 'g') {
            staff[7][staff[0].size()-1] = '*';
        }
        if(note == 'f') {
            staff[8][staff[0].size()-1] = '*';
        }
        if(note == 'e') {
            staff[9][staff[0].size()-1] = '*';
        }
        if(note == 'd') {
            staff[10][staff[0].size()-1] = '*';
        }
        if(note == 'c') {
            staff[11][staff[0].size()-1] = '*';
        }
        if(note == 'b') {
            staff[12][staff[0].size()-1] = '*';
        }
        if(note == 'a') {
            staff[13][staff[0].size()-1] = '*';
        }
}

int main() {
    vector<string> staff = {"G: ",
                            "F: ",
                            "E: ",
                            "D: ",
                            "C: ",
                            "B: ",
                            "A: ",
                            "g: ",
                            "f: ",
                            "e: ",
                            "d: ",
                            "c: ",
                            "b: ",
                            "a: "};

    int notes;
    cin >> notes;

    for(int i = 0; i < notes; i++) {
        string note;
        cin >> note;

        addspace(staff);
        addnote(staff, note[0]);
        if(note.size() > 1) {
            for(int j = 0; j < note[1] - '1'; j++) {
                addspace(staff);
                addnote(staff, note[0]);
            }
        }

        if(i != notes-1) {
            addspace(staff);
        }
    }

    for(auto i : staff) {
        cout << i << endl;
    }
}
