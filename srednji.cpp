#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n, med;
    cin >> n >> med;

    vector<int> v(n);
    int pos;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] == med) {
            pos = i;
        }
    }

    map<int,int> m;
    m[0] = 1;
    int sum = 0;
    for(int i = pos+1; i < n; i++) {
        if(v[i] > med) sum++;
        else sum--;
        m[sum]++;
    }

    ll ans = m[0];
    sum = 0;
    for(int i = pos-1; i >= 0; i--) {
        if(v[i] > med) sum++;
        else sum--;
        ans += m[-sum];
    }

    cout << ans << endl;
}
