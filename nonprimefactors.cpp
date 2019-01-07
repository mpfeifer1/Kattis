#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 2000001;
ll factors[MAXN];
ll pfactors[MAXN];

int count(int j, int i) {
    int sum = 0;
    while(j % i == 0) {
        sum++;
        j/=i;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int i = 0; i < MAXN; i++) factors[i] = 1;
    for(int i = 0; i < MAXN; i++) pfactors[i] = 0;

    for(int i = 2; i < MAXN; i++) {
        if(pfactors[i] == 0) {
            for(int j = i*2; j < MAXN; j += i) {
                pfactors[j]++;
                factors[j] *= (1+count(j,i));
            }
        }
    }

    int cases;
    cin >> cases;

    while(cases--) {
        int t;
        cin >> t;
        cout << factors[t] - pfactors[t] << '\n';
    }
}
