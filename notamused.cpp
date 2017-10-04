#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    string s;
    int count = 1;

    map<string, vector<int>> times;

    bool first = true;

    while(cin >> s) {
        // If the park is opening
        if(s == "OPEN") {
            if(first) {
                first = false;
            }
            else {
                cout << endl;
            }

            cout << "Day " << count << endl;
            count++;
            continue;
        }

        // If the park is closing
        if(s == "CLOSE") {
            // Print each customer
            for(auto i : times) {
                double total = 0;
                for(int j = 0; j < i.second.size(); j += 2) {
                    total += i.second[j+1] - i.second[j];
                }
                total /= 10;
                cout << fixed;
                cout.precision(2);
                // Calculate times here, print
                cout << i.first << " $" << total << endl;
            }

            // Reset the map
            times.clear();

            continue;
        }

        // Read in the person's data
        string name;
        int time;
        cin >> name >> time;
        times[name].push_back(time);
    }
}
