#include <bits/stdc++.h>

using namespace std;
int inf = 1 << 30;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> suml(m,0);
    vector<int> sumr(m,0);

    // Read in input
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if(i % 2 == 0) {
            sumr[t-1]++;
        }
        else {
            suml[m-t]++;
        }
    }

    // Calculate prefix sums
    int sum = 0;
    for(int i = m-1; i >= 0; i--) {
        sum += sumr[i];
        sumr[i] = sum;
    }

    sum = 0;
    for(int i = 0; i < m; i++) {
        sum += suml[i];
        suml[i] = sum;
    }

    // Find minimum value
    int best = inf;
    int count = 0;
    for(int i = 0; i < m; i++) {
        if(suml[i] + sumr[i] < best) {
            best = suml[i] + sumr[i];
            count = 0;
        }
        if(suml[i] + sumr[i] == best) {
            count++;
        }
    }

    // Print answer
    cout << best << " " << count << endl;
}
