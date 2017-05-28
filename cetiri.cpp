#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool works(vector<int> v, int n) {
    v.push_back(n);
    sort(v.begin(), v.end());

    bool works = true;
    for(int i = 0; i < v.size() - 2; i++) {
        if(v[i+1]-v[i] != v[i+2]-v[i+1]) {
            works = false;
        }
    }

    return works;
}

int main() {
    vector<int> v;
    v.resize(3);
    cin >> v[0] >> v[1] >> v[2];

    sort(v.begin(), v.end());

    vector<int> possible;
    int diff1 = v[2]-v[1];
    int diff2 = v[1]-v[0];

    possible.push_back(v[0]+diff1);
    possible.push_back(v[1]+diff1);
    possible.push_back(v[2]+diff1);
    possible.push_back(v[0]-diff1);
    possible.push_back(v[1]-diff1);
    possible.push_back(v[2]-diff1);

    possible.push_back(v[0]+diff2);
    possible.push_back(v[1]+diff2);
    possible.push_back(v[2]+diff2);
    possible.push_back(v[0]-diff2);
    possible.push_back(v[1]-diff2);
    possible.push_back(v[2]-diff2);

    for(auto i : possible) {
        if(works(v, i)) {
            cout << i << endl;
            break;
        }
    }
}
