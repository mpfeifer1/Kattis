#include <iostream>
#include <map>

using namespace std;

int part(map<pair<int,int>, int>& memo, int n, int m, int power) {
    if(n == 0) {
        return 1;
    }
    if(power <= 0) {
        return 0;
    }
    if(power == 1) {
        return 1;
    }

    pair<int, int> idx = {n, power};
    if(memo.count(idx)) {
        return memo[idx];
    }

    int sum = 0;
    if(n >= power) {
        sum = part(memo, n-power, m, power);
    }
    if(power >= 1) {
        sum += part(memo, n, m, power/m);
    }

    memo[idx] = sum;

    return sum;
}

int main() {
    int n;
    cin >> n;

    while(n--) {
        int garbo, m, n;
        cin >> garbo >> m >> n;
        cout << garbo;

        map<pair<int, int>, int> memo;
        int power = m;

        while(power <= n) {
            power *= m;
        }

        cout << " " << part(memo, n, m, power) << endl;
    }
}
