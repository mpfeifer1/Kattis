#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int stops;
        cin >> stops;

        int s, l, temp;
        cin >> temp;
        s = temp;
        l = temp;

        for(int i = 0; i < stops - 1; i++) {
            cin >> temp;
            s = min(s, temp);
            l = max(l, temp);
        }

        cout << (l - s) * 2 << endl;
    }
}
