#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Setup
    vector<int> nextStep;
    nextStep.resize(100, -1);

    int kitten;
    cin >> kitten;

    int n;
    cin.ignore();

    // Store all input into tree
    while(cin >> n && n != -1) {
        string s;
        getline(cin, s);

        stringstream line(s);

        int temp;
        while(line >> temp) {
            nextStep[temp] = n;
        }
    }

    while(kitten != -1) {
        cout << kitten << " ";
        kitten = nextStep[kitten];
    }
    cout << endl;
}
