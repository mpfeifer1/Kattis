#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int size;
        cin >> size;
        vector<int> v;
        int incorrect = 0;

        for(int j = 0; j < size; j++) {
            int temp;
            cin >> temp;
            v.push_back(temp);
            int s = v.size();
            if(v[s-1] < v[s-2]) {
                incorrect++;
            }
        }

        cout << incorrect << endl;
    }
}
