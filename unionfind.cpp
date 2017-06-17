#include <iostream>
#include <vector>

using namespace std;

int setfind(int a, vector<int>& v) {
    if(v[a] < 0) {
        return a;
    }

    v[a] = setfind(v[a], v);
    return v[a];
}

void setunion(int a, int b, vector<int>& v) {
    int tempa = setfind(a, v);
    int tempb = setfind(b, v);

    // Same number
    if(tempa == tempb) {
        return;
    }

    // If both representative, make b point to a
    if(v[tempa] < 0 && v[tempb] < 0) {
        v[tempb] = tempa;
        return;
    }

    // B representative
    if(v[tempa] >= 0 && v[tempb] < 0) {
        v[tempa] = tempb;
        return;
    }

    // A representative
    if(v[tempa] < 0 && v[tempb] >= 0) {
        v[tempb] = tempa;
        return;
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> v;
    v.resize(m+1, -1);

    for(int i = 0; i < n; i++) {
        char c;
        int q1, q2;
        cin >> c >> q1 >> q2;

        if(c == '?') {
            if(setfind(q1, v) == setfind(q2, v)) {
                cout << "yes" << endl;
            }
            else {
                cout << "no" << endl;
            }
        }
        else {
            setunion(q1, q2, v);
        }
    }
}
