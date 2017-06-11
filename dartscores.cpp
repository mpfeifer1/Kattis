#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int score = 0;
        int throws;
        cin >> throws;

        for(int j = 0; j < throws; j++) {
            double x, y;
            cin >> x >> y;
            double dist = sqrt(pow(x, 2) + pow(y, 2));

            if(dist == 0) {
                score--;
            }

            while(dist <= 200) {
                score++;
                dist += 20;
            }
        }

        cout << score << endl;
    }
}
