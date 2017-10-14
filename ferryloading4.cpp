#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int cases;
    cin >> cases;

    while(cases--) {
        int size, cars;
        cin >> size >> cars;
        size *= 100;

        // Read cars into list
        vector<int> r;
        vector<int> l;
        for(int i = 0; i < cars; i++) {
            int size;
            string side;
            cin >> size >> side;

            if(side == "left") {
                l.push_back(size);
            }
            if(side == "right") {
                r.push_back(size);
            }
        }

        // Simulate
        int trips = 0;
        while(l.size() > 0 || r.size() > 0) {
            int l_remaining = size;
            while(l.size() > 0 && l.back() <= l_remaining) {
                l_remaining -= l.back();
                l.pop_back();
            }
            trips++;

            if(l.size() == 0 && r.size() == 0) {
                break;
            }

            int r_remaining = size;
            while(r.size() > 0 && r.back() <= r_remaining) {
                r_remaining -= r.back();
                r.pop_back();
            }
            trips++;
        }

        cout << trips << endl;
    }
}
