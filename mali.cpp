#include <bits/stdc++.h>

using namespace std;

int calc(vector<int> v1, vector<int> v2) {
    int p1 = 0;
    int p2 = 100;

    int worst = 0;

    bool broken = false;
    while(true) {
        while(v1[p1] == 0) {
            p1++;
            if(p1 > 100) {
                broken = true;
                break;
            }
        }
        while(v2[p2] == 0) {
            p2--;
            if(p2 < 0) {
                broken = true;
                break;
            }
        }

        if(broken) break;

        worst = max(worst, p1+p2);

        int m = min(v1[p1], v2[p2]);
        v1[p1] -= m;
        v2[p2] -= m;
    }

    return worst;
}

int main() {
    int n;
    cin >> n;

    vector<int> v1(101,0);
    vector<int> v2(101,0);

    for(int i = 0; i < n; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        v1[n1]++;
        v2[n2]++;
        cout << calc(v1,v2) << endl;
    }
}
