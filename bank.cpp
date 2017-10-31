#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> best(t+1, 0);

    for(int i = 0; i < n; i++) {
        int money, time;
        cin >> money >> time;

        for(int j = time; j >= 0; j--) {
            if(money > best[j]) {
                swap(money, best[j]);
            }
        }
    }

    int total = 0;
    for(auto i : best) {
        total += i;
    }

    cout << total << endl;
}
