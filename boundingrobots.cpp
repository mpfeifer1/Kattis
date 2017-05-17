#include <iostream>
#include <cmath>

using namespace std;

int range(int small, int large, int val) {
    int ans = val;
    ans = min(large, ans);
    ans = max(small, ans);
    return ans;
}

int main() {
    int w, l;
    while(cin >> w && cin >> l && (w != 0 && l != 0)) {
        int n;
        cin >> n;

        int actualX = 0, robotX = 0;
        int actualY = 0, robotY = 0;

        for(int i = 0; i < n; i++) {
            char dir;
            cin >> dir;
            int dist;
            cin >> dist;

            if(dir == 'u') {
                robotY  += dist;
                actualY += dist;
            }
            if(dir == 'd') {
                robotY  -= dist;
                actualY -= dist;
            }
            if(dir == 'l') {
                robotX  -= dist;
                actualX -= dist;
            }
            if(dir == 'r') {
                robotX  += dist;
                actualX += dist;
            }

            actualY = range(0, l-1, actualY);
            actualX = range(0, w-1, actualX);
        }

        cout << "Robot thinks " << robotX << " " << robotY << endl;
        cout << "Actually at " << actualX << " " << actualY << endl;
        cout << endl;

    }
}
