#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c) {
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y');
}

string piglatin(string s) {
    if(isVowel(s[0])) {
        s += "yay";
        return s;
    }

    string temp;
    int i = 0;
    while(!isVowel(s[i])) {
        temp += s[i];
        i++;
    }

    s.erase(0, i);
    s += temp;
    s += "ay";

    return s;
}

int main() {
    string s;

    while(cin >> s) {

        cout << piglatin(s) << " ";

        if(cin.peek() == '\n') {
            cout << endl;
        }
    }
}
