#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        vector<int> r, b;

        int pieces;
        cin >> pieces;

        for(int j = 0; j < pieces; j++) {
            int num;
            char color;

            cin >> num;
            cin >> color;

            num--;

            if(color == 'R') {
                r.push_back(num);
            }
            else {
                b.push_back(num);
            }
        }

        sort(r.rbegin(), r.rend());
        sort(b.rbegin(), b.rend());

        int size = min(r.size(), b.size());

        int length = 0;

        for(int j = 0; j < size; j++) {
            length += b[j];
            length += r[j];
        }

        cout << "Case #" << i+1 << ": " << length << endl;
    }
}
