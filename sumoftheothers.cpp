#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;

    while(getline(cin, s)) {
        istringstream is(s);

        vector<int> v;

        int sum = 0;

        int n;
        while(is >> n) {
            v.push_back(n);
            sum += n;
        }

        bool printed = false;
        for(auto i : v) {
            if(sum - 2*i == 0 && !printed) {
                cout << i << endl;
                printed = true;
            }
        }

    }
}
