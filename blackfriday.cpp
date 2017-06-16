#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> people;
    vector<int> rolls;

    rolls.resize(7, 0);

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        people.push_back(temp);
        rolls[temp]++;
    }

    bool found = false;
    for(int i = 6; i >= 1; i--) {
        if(rolls[i] == 1) {
            for(int j = 0; j < people.size(); j++) {
                if(people[j] == i) {
                    cout << j+1 << endl;
                    return 0;
                }
            }
        }
    }

    if(!found) {
        cout << "none" << endl;
    }
}
