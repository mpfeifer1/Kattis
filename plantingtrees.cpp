#include <bits/stdc++.h>

using namespace std;

int main() {
    int trees;
    cin >> trees;
    vector<int> t;
    t.resize(trees+1);
    for(int i = 0; i < trees; i++) {
        int temp;
        cin >> temp;
        t[i] = temp;
    }

    sort(t.rbegin(), t.rend());

    int partayTime = 0;
    for(int i = 0; i < trees; i++) {
        if(t[i] + i > partayTime) {
            partayTime = t[i] + i;
        }
    }

    cout << partayTime + 2 << endl;
}
