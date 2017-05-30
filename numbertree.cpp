#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    string path;
    cin >> path;

    int maxi = pow(2, n + 1);

    int pos = 1;
    for(auto c : path) {
        pos *= 2;
        if(c == 'R') {
            pos++;
        }
    }

    cout << maxi - pos << endl;
}
