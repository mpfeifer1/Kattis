#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    while(cases--) {
        ll garbo, size;
        cin >> garbo >> size;

        cout << garbo << " ";

        vector<ll> v;
        for(int i = 0; i < size; i++) {
            ll temp;
            cin >> temp;
            v.push_back(temp);
        }

        vector<ll> s = v;
        sort(s.begin(), s.end());

        int index = 0;
        for(int i = 0; i < size; i++) {
            if(v[i] == s[index]) {
                index++;
            }
        }

        cout << size - index << endl;
    }
}
