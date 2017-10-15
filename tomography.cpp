#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int s1, s2;
    cin >> s1 >> s2;

    vector<int> v1, v2;

    for(int i = 0; i < s1; i++) {
        int temp;
        cin >> temp;
        v1.push_back(temp);
    }

    for(int i = 0; i < s2; i++) {
        int temp;
        cin >> temp;
        v2.push_back(temp);
    }

    sort(v1.rbegin(), v1.rend());
    sort(v2.rbegin(), v2.rend());

    for(auto i : v1) {
        for(int j = 0; j < i; j++) {
            v2[j]--;
        }
        sort(v2.rbegin(), v2.rend());
    }

    bool works = true;
    for(auto i : v2) {
        works &= (i == 0);
    }

    if(works) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
