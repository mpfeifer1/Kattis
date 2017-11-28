#include <bits/stdc++.h>

using namespace std;

int inf = 1 << 30;

int main() {
    int maxv = 2000006;

    vector<int> dp(maxv, inf);
    vector<int> greedy(maxv, inf);

    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());

    dp[0] = 0;
    greedy[0] = 0;

    int ptr = 0;
    bool works = true;

    for(int i = 1; i < maxv; i++) {
        while(ptr < n-1 && a[ptr+1] <= i) {
            ptr++;
        }

        greedy[i] = greedy[i - a[ptr]] + 1;

        for(int j = 0; j < n && a[j] <= i; j++) {
            dp[i] = min(dp[i], dp[i - a[j]] + 1);
        }

        if(greedy[i] != dp[i]) {
            works = false;
            break;
        }
    }

    if(works) {
        cout << "canonical" << endl;
    }
    else {
        cout << "non-canonical" << endl;
    }
}
