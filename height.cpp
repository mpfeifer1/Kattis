#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        cout << temp << " ";

        vector<int> v;
        v.resize(20);
        for(int j = 0; j < 20; j++) {
            cin >> v[j];
        }

        int steps = 0;

        while(v.size() > 0) {
            int m = 0;
            for(int j = 1; j < v.size(); j++) {
                if(v[j] < v[m]) {
                    m = j;
                }
            }

            steps += m;
            v.erase(v.begin() + m);
        }

        cout << steps << endl;
    }
}
