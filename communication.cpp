#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> ans;
    ans.resize(1024, -1);

    for(int i = 0; i < 511; i++) {
        int temp = i ^ (i << 1) & 255;
        ans[temp] = i;
    }

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        cout << ans[temp] << " ";
    }

    cout << endl;
}
