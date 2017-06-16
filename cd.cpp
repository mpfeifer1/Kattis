#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m;

    while(cin >> n >> m && n != 0 && m != 0) {
        vector<int> jack, jill, ans;

        int temp;
        for(int i = 0; i < n; i++) {
            cin >> temp;
            jack.push_back(temp);
        }

        for(int i = 0; i < m; i++) {
            cin >> temp;
            jill.push_back(temp);
        }

        set_intersection(jack.begin(), jack.end(), jill.begin(), jill.end(), back_inserter(ans));

        cout << ans.size() << endl;
    }
}
