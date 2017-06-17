#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long ull;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;

        int leftover = 0;

        for(int j = 0; j < num; j++) {
            ull temp;
            cin >> temp;

            leftover += temp % num;
        }

        if(leftover % num == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
