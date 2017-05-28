#include <iostream>

using namespace std;

int solve(int l, int r) {
    if(l == r) {
        return 1;
    }

    if(l > r) {
        return 2 * solve(l-r, r) + 1;
    }

    if(l < r) {
        return 2 * solve(l, r-l);
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        cout << temp << " ";

        int l, r;
        cin >> l;
        cin.ignore();
        cin >> r;

        cout << solve(l, r) << endl;
    }
}
