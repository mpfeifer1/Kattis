#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    int wins = 0;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        wins++;
        for(int i = 0; i < s.size()-1; i++) {
            if(s[i] == 'C' && s[i+1] == 'D') {
                wins--;
                break;
            }
        }
    }

    cout << wins << endl;
}
