#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    while(cin >> n && n != 0) {
        vector<int> reg;
        reg.resize(32, -1);

        for(int i = 0; i < n; i++) {
            string op;
            int in1;
            int in2;

            cin >> op;
            if(op == "SET") {
                cin >> in1;
                reg[in1] = 1;
            }
            if(op == "CLEAR") {
                cin >> in1;
                reg[in1] = 0;
            }
            if(op == "AND") {
                cin >> in1;
                cin >> in2;

                if(reg[in1] == 1 && reg[in2] == 1) {
                    reg[in1] = 1;
                }
                else if(reg[in1] == 0 || reg[in2] == 0) {
                    reg[in1] = 0;
                }
                else {
                    reg[in1] = -1;
                }
            }
            if(op == "OR") {
                cin >> in1;
                cin >> in2;

                if(reg[in1] == 1 || reg[in2] == 1) {
                    reg[in1] = 1;
                }
                else if (reg[in1] == 0 && reg[in2] == 0) {
                    reg[in1] = 0;
                }
                else {
                    reg[in1] = -1;
                }
            }
        }

        reverse(reg.begin(), reg.end());

        for(auto i : reg) {
            if(i == -1) {
                cout << "?";
            }
            else {
                cout << i;
            }
        }

        cout << endl;
    }
}
