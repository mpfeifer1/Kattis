#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;

    int cities, pilots, a, b, i, j;
    for(i = 0; i < cases; i++) {
        cin >> cities >> pilots;

        for(j = 0; j < pilots; j++) {
            cin >> a >> b;
        }

        cout << cities - 1 << endl;
    }
}
