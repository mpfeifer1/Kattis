#include <iostream>

using namespace std;

int main() {
    string note, tonality;
    int i = 1;
    while(cin >> note && cin >> tonality) {
        cout << "Case " << i << ": ";

        bool unique = true;

        if(note == "A#") {
            unique = false;
            cout << "Bb";
        }
        if(note == "Bb") {
            unique = false;
            cout << "A#";
        }
        if(note == "C#") {
            unique = false;
            cout << "Db";
        }
        if(note == "Db") {
            unique = false;
            cout << "C#";
        }
        if(note == "D#") {
            unique = false;
            cout << "Eb";
        }
        if(note == "Eb") {
            unique = false;
            cout << "D#";
        }
        if(note == "F#") {
            unique = false;
            cout << "Gb";
        }
        if(note == "Gb") {
            unique = false;
            cout << "F#";
        }
        if(note == "G#") {
            unique = false;
            cout << "Ab";
        }
        if(note == "Ab") {
            unique = false;
            cout << "G#";
        }

        if(!unique) {
            cout << " " << tonality << endl;
        }
        else {
            cout << "UNIQUE" << endl;
        }

        i++;
    }
}
