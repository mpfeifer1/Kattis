#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, vector<int>> vacations;
    unordered_set<string> destinations;

    for(int i = 0; i < n; i++) {
        string dest;
        cin >> dest;

        int year;
        cin >> year;

        destinations.insert(dest);

        if(vacations.count(dest) < 1) {
            vector<int> v;
            v.push_back(year);
            vacations.insert({dest, v});
        }
        else {
            vector<int>& temp = vacations[dest];
            temp.push_back(year);
        }
    }

    int m;
    cin >> m;

    for(auto d : destinations) {
        vector<int>& temp = vacations[d];
        sort(temp.begin(), temp.end());
    }

    for(int i = 0; i < m; i++) {
        string dest;
        cin >> dest;

        int trip;
        cin >> trip;

        vector<int>& temp = vacations[dest];

        cout << temp[trip-1] << endl;
    }
}
