#include <bits/stdc++.h>
using namespace std;

int main() {
    int row, col, n;
    cin >> row >> col >> n;
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; ++i) {
        int I, J;
        cin >> I >> J;
        arr[i] = {I,J};
    }
    sort(arr.begin(), arr.end());
    int prevRow = 1;
    int i = 0;
    while(i < n) {
        int j = i;
        vector<int> cols;
        while(j < n && arr[i].first == arr[j].first) {
            cols.push_back(arr[j].second);
            ++j;
        }
        if(arr[i].first == arr.back().first) arr[i].first = row;
        int prevCol = 1;
        for(int k = 0; k+1 < cols.size(); ++k) {
            cout << prevRow << ' ' << prevCol << ' ' << arr[i].first << ' ' << cols[k] << '\n';
            prevCol = cols[k]+1;
        }
        cout << prevRow << ' ' << prevCol << ' ' << arr[i].first << ' ' << col << '\n';
        prevRow = arr[i].first+1;
        i = j;
    }
    cout << "0\n";
}
