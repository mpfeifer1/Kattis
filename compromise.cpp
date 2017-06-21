#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        // Take in input as vector of strings
        vector<string> input;
        for(int j = 0; j < a; j++) {
            string temp;
            cin >> temp;
            input.push_back(temp);
        }

        // Create a vector of the sum
        vector<double> totals;
        totals.resize(b, 0);
        for(int j = 0; j < a; j++) {
            for(int k = 0; k < b; k++) {
                totals[k] += input[j][k] - '0';
            }
        }

        // Make it a vector of averages
        for(int j = 0; j < b; j++) {
            totals[j] /= a;
        }

        // Print anwer
        for(auto c : totals) {
            if(c < .5) {
                cout << "0";
            }
            else {
                cout << "1";
            }
        }
        cout << endl;
    }
}
