#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int passwords;
    cin >> passwords;

    vector<double> probabilities;

    for(int i = 0; i < passwords; i++) {
        string garbage;
        double prob;
        cin >> garbage >> prob;
        probabilities.push_back(prob);
    }

    sort(probabilities.rbegin(), probabilities.rend());

    double total = 0;
    for(int i = 1; i <= passwords; i++) {
        total += probabilities[i-1] * i;
    }

    cout << fixed;
    cout.precision(5);

    cout << total << endl;
}
