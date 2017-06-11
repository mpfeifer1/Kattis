#include <iostream>

using namespace std;

int main() {
    int m, p, l;
    int e;
    int r, s;
    int n;

    while(cin >> m && cin >> p && cin >> l) {
        cin >> e >> r >> s >> n;

        for(int i = 0; i < n; i++) {
            int temp_m, temp_p, temp_l;
            temp_l = e * m;
            temp_p = l / r;
            temp_m = p / s;
            m = temp_m;
            l = temp_l;
            p = temp_p;
        }

        cout << m << endl;
    }
}
