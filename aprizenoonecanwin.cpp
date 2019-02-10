#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int res = 1;
    for(int i = 1; i < n; ++i) {
        if(arr[i] + arr[i-1] <= x) res = i+1;
    }
    cout << res << '\n';
    return 0;
}
