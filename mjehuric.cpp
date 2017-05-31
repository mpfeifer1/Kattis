#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

void print() {
    for(int i = 0; i < 5; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    v.resize(5);
    cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4];

    while(!is_sorted(v.begin(), v.end())) {
        if(v[0] > v[1]) {
            swap(v[0], v[1]);
            print();
        }
        if(v[1] > v[2]) {
            swap(v[1], v[2]);
            print();
        }
        if(v[2] > v[3]) {
            swap(v[2], v[3]);
            print();
        }
        if(v[3] > v[4]) {
            swap(v[3], v[4]);
            print();
        }
    }
}
