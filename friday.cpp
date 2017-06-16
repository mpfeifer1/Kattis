#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int d, m;
        cin >> d >> m;

        vector<int> year;

        for(int i = 0; i < m; i++) {
            int days;
            cin >> days;

            for(int i = 1; i <= days; i++) {
                year.push_back(i);
            }
        }

        int fridays = 0;

        for(int i = 0; i < d; i++) {
            if(year[i] == 13 && i % 7 == 5) {
                fridays++;
            }
        }

        cout << fridays << endl;
    }
}
