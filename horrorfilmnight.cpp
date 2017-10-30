#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<bool> v1, v2;
    v1.resize(1000000, false);
    v2.resize(1000000, false);

    int s;

    cin >> s;
    for(int i = 0; i < s; i++) {
        int temp;
        cin >> temp;
        v1[temp] = true;
    }

    cin >> s;
    for(int i = 0; i < s; i++) {
        int temp;
        cin >> temp;
        v2[temp] = true;
    }

    bool h1 = true, h2 = true;
    int total = 0;
    for(int i = 0; i < 1000000; i++) {
        if(v1[i] && v2[i]) {
            h1 = true;
            h2 = true;
            total++;
        }
        else if(v1[i] && h2) {
            h1 = true;
            h2 = false;
            total++;
        }
        else if(v2[i] && h1) {
            h1 = false;
            h2 = true;
            total++;
        }
    }

    cout << total << endl;
}
