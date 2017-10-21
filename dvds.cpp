#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int size;
        cin >> size;
        vector<int> v;

        for(int j = 0; j < size; j++) {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }

        int minfound = 0;
        for(auto i : v) {
            if(i == minfound+1) {
                minfound++;
            }
        }

        cout << size - minfound << endl;
    }
}
