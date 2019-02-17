#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& i : v) {
        cin >> i;
    }
    sort(v.rbegin(),v.rend());

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] >= i+1) {
            ans = i+1;
        }
        else break;
    }

    cout << ans << endl;
}
