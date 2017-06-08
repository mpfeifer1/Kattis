#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;

    for(int i = 0; i < 6; i++) {
        int temp;
        cin >> temp;

        v.push_back(temp);
    }

    int h1, h2;
    cin >> h1 >> h2;

    sort(v.begin(), v.end());

    while(next_permutation(v.begin(), v.end())) {
        if(v[0] + v[1] + v[2] == h1 && v[3] + v[4] + v[5] == h2) {
            vector<int> t1, t2;
            t1.push_back(v[0]);
            t1.push_back(v[1]);
            t1.push_back(v[2]);
            t2.push_back(v[3]);
            t2.push_back(v[4]);
            t2.push_back(v[5]);

            sort(t1.rbegin(), t1.rend());
            sort(t2.rbegin(), t2.rend());

            cout << t1[0] << " " << t1[1] << " " << t1[2] << " ";
            cout << t2[0] << " " << t2[1] << " " << t2[2] << endl;
            break;
        }
    }
}
