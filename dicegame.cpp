#include <iostream>

using namespace std;

int main() {
    int e1, e2, e3, e4;
    int g1, g2, g3, g4;

    cin >> e1 >> e2 >> e3 >> e4;
    cin >> g1 >> g2 >> g3 >> g4;

    int e = e1 + e2 + e3 + e4;
    int g = g1 + g2 + g3 + g4;

    if(e > g) {
        cout << "Gunnar" << endl;
    }
    else if(e < g) {
        cout << "Emma" << endl;
    }
    else {
        cout << "Tie" << endl;
    }
}
