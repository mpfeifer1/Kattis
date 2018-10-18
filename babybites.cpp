#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    bool found = false;
    int diff;

    bool works = true;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if(s == "mumble") {
            continue;
        }
        int t = stoi(s);
        if(t != i+1) works = false;
    }

    if(works) {
        cout << "makes sense" << endl;
    }
    else {
        cout << "something is fishy" << endl;
    }
}
