#include <iostream>
#include <vector>

using namespace std;

int main() {
    int size;
    cin >> size;

    int diagonal = size * 2 - 1;

    vector<bool> a;
    vector<bool> b;
    vector<bool> c;
    vector<bool> d;

    a.resize(diagonal, false);
    b.resize(diagonal, false);
    c.resize(size, false);
    d.resize(size, false);


    int x, y;
    for(int i = 0; i < size; i++) {
        cin >> x >> y;
        if(a[y-x+size-1] || b[x+y] || c[x] || d[y]) {
            cout << "INCORRECT" << endl;
            return 0;
        }
        a[y - x + size-1] = true;
        b[x + y] = true;
        c[x] = true;
        d[y] = true;
    }

    cout << "CORRECT" << endl;

    return 0;
}
