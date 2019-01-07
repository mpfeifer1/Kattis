#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<bool> keep(365,false);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        for(int j = n1-1; j <= n2-1; j++) {
            keep[j] = true;
        }
    }

    int sum = 0;
    for(int i = 0; i < 365; i++) {
        if(keep[i]) sum++;
    }

    cout << sum << endl;
}
