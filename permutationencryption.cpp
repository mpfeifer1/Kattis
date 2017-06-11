#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    while(cin >> n && n != 0) {
        vector<int> permuted;
        for(int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            permuted.push_back(temp);
        }

        string s;
        cin.ignore();
        getline(cin, s);

        while(s.size() % n != 0) {
            s.push_back(' ');
        }

        int segments = s.size() / n;

        string encrypt = "";
        for(int i = 0; i < segments; i++) {
            for(auto j : permuted) {
                encrypt += s[i*n+j-1];
            }
        }

        cout << '\'' << encrypt << '\'' << endl;
    }
}
