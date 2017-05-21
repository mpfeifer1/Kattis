#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    cin.ignore();
    for(int i = 0; i < n; i++) {
        vector<bool> letters;
        letters.resize(26, false);

        string s;
        getline(cin, s);
        int used = 0;

        for(auto c : s) {
            int temp = tolower(c) - 'a';
            if(temp < 26 && temp >= 0 && !letters[temp]) {
                letters[temp] = true;
                used++;
            }
        }

        if(used == 26) {
            cout << "pangram";
        }
        else {
            cout << "missing ";
            for(int j = 0; j < 26; j++) {
                if(!letters[j]) {
                    cout << (char) (j + 'a');
                }
            }
        }

        cout << endl;
    }
}
