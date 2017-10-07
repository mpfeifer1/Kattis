#include <bits/stdc++.h>

using namespace std;

int main() {
    int total, num, temp1, temp2;

    cin >> total;

    for(int i = 0; i < total; i++) {
        bool test = true;
        temp1 = 0;
        num = 0;
        cin >> num;
        cin >> temp1;
        for(int i = 1; i < num; i++) {
            temp2 = temp1;
            cin >> temp1;
            if(temp2+1 != temp1 && test) {
                cout << i+1 << endl;
                test = false;
            }

        }
    }

}
