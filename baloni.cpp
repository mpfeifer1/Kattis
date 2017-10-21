#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> counts;
    counts.resize(1000001, 0);

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        if(counts[temp] == 0) {
            counts[temp-1]++;
        }
        else {
            counts[temp-1]++;
            counts[temp]--;
        }
    }

    int throws = 0;
    for(int i = 0; i < 1000000; i++) {
        throws += counts[i];
    }
    cout << throws << endl;
}
