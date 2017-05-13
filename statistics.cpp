#include <iostream>

using namespace std;

int main() {
    int i = 1;
    int n;

    while(cin >> n) {
        int min;
        int max;
        cin >> max;
        min = max;

        for(int j = 0; j < n-1; j++) {
            int temp;
            cin >> temp;
            if(temp < min) {
                min = temp;
            }
            if(temp > max) {
                max = temp;
            }
        }

        cout << "Case " << i << ": " << min << " " << max
             << " " << max-min << endl;
        i++;
    }
}
