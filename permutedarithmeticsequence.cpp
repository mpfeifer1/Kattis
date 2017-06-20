#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool isarithmetic(vector<int>& v) {
    int skip = v[0] - v[1];
    bool works = true;

    for(int i = 0; i < v.size() - 1; i++) {
        if(v[i] - v[i+1] != skip) {
            works = false;
            break;
        }
    }

    return works;
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;

        vector<int> seq;

        for(int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            seq.push_back(temp);
        }

        if(isarithmetic(seq)) {
            cout << "arithmetic" << endl;
            continue;
        }

        sort(seq.begin(), seq.end());

        if(isarithmetic(seq)) {
            cout << "permuted arithmetic" << endl;
            continue;
        }

        cout << "non-arithmetic" << endl;
    }
}
