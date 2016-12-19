#include <iostream>
#include <vector>

using namespace std;

int main() {
    int size;
    cin >> size;

    vector<int> plans;
    plans.resize(size, 0);

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            int num;
            cin >> num;
            plans[i] |= num;
        }
    }

    for(int i = 0; i < size; i++) {
        cout << plans[i] << " ";
    }
    cout << endl;
}
