#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    vector<vector<int>> arr;
    arr.resize(a);

    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            int temp;
            cin >> temp;
            arr[i].push_back(temp);
        }
    }

    for(int i = 1; i < a; i++) {
        arr[i][0] += arr[i-1][0];
    }

    for(int j = 1; j < b; j++) {
        arr[0][j] += arr[0][j-1];
    }

    for(int i = 1; i < a; i++) {
        for(int j = 1; j < b; j++) {
            int x = arr[i][j-1];
            int y = arr[i-1][j];
            arr[i][j] += max(x,y);
        }
    }

    for(int i = 0; i < a; i++) {
        cout << arr[i][b-1] << " ";
    }
    cout << endl;
}
