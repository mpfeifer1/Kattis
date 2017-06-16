#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool checkspace(vector<double>& v, double mower) {
    for(int i = 0; i < v.size() - 1; i++) {
        if(v[i+1] - v[i] > mower) {
            return false;
        }
    }
    return true;
}

int main() {
    int nx, ny;
    double mower;

    while(cin >> nx >> ny >> mower && nx != 0 && ny != 0 && mower != 0) {
        vector<double> width, length;

        for(int i = 0; i < nx; i++) {
            double temp;
            cin >> temp;
            width.push_back(temp);
        }

        for(int i = 0; i < ny; i++) {
            double temp;
            cin >> temp;
            length.push_back(temp);
        }

        sort(width.begin(), width.end());
        sort(length.begin(), length.end());

        bool l = false, w = false;
        if(checkspace(width, mower) && width[0] <= mower/2 && width[nx-1] >= 75 - mower/2) {
            l = true;
        }
        if(checkspace(length, mower) && length[0] <= mower/2 && length[ny-1] >= 100 - mower/2) {
            w = true;
        }

        if(l && w) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
