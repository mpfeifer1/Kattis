#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    while(true) {
        int n;
        cin >> n;
        if(n == 0) {
            return 0;
        }

        vector<string> v;

        for(int i = 0; i < n; i++) {
            string temp;
            cin >> temp;
            v.push_back(temp);
        }

        vector<string> o;
    }
}
