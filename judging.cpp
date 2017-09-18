#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> dom;
    vector<string> kattis;

    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        dom.push_back(temp);
    }

    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        kattis.push_back(temp);
    }

    sort(dom.begin(), dom.end());
    sort(kattis.begin(), kattis.end());

    int matches = 0;
    while(dom.size() > 0 && kattis.size() > 0) {
        if(kattis.back() == dom.back()) {
            dom.pop_back();
            kattis.pop_back();
            matches++;
        }
        else if(kattis.back() < dom.back()) {
            dom.pop_back();
        }
        else {
            kattis.pop_back();
        }
    }

    cout << matches << endl;
}
