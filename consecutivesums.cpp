#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void print(int n, int start, int nums) {
    cout << n << " = ";
    for(int i = 0; i < nums; i++) {
        cout << start+i;
        if(i != nums-1) cout << " + ";
    }
    cout << endl;
}

void solve() {
    ll n;
    cin >> n;

    ll nums = 2;
    while(true) {
        ll sub = nums * (nums-1) / 2;

        ll temp = n - sub;
        if(temp <= 0) break;


        if(temp % nums == 0) {
            print(n, temp / nums, nums);
            return;
        }

        nums++;
    }

    cout << "IMPOSSIBLE" << endl;
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
