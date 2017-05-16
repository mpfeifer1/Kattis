#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, bool> people;

    for(int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        // If they are in the data structure
        if(people.count(s2) > 0) {
            // If they enter
            if(s1 == "entry") {
                // If already inside
                if(people[s2] == 1) {
                    cout << s2 << " entered (ANOMALY)" << endl;
                }
                // If not inside
                else {
                    people[s2] = 1;
                    cout << s2 << " entered" << endl;
                }
            }
            // If they exit
            else {
                // If already inside
                if(people[s2] == 1) {
                    people[s2] = 0;
                    cout << s2 << " exited" << endl;
                }
                // If not inside
                else {
                    cout << s2 << " exited (ANOMALY)" << endl;
                }
            }
        }

        // If they are not in the structure
        else {
            // If they enter
            if(s1 == "entry") {
                people.insert({s2, 1});
                cout << s2 << " entered" << endl;
            }
            // If they exit
            else {
                people.insert({s2, 0});
                cout << s2 << " exited (ANOMALY)" << endl;
            }
        }
    }
}
