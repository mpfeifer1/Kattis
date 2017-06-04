#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    int problems;
    cin >> problems;
    for(int z = 0; z < problems; z++) {
        int input[6] = {0};
        //cin >> input[0] >> input[1] >> input[2] >> input[3] >> input[4] >> input[5];
        int L1, A1, L2, A2, LT, AT;
        cin >> L1 >> A1 >> L2 >> A2 >> LT >> AT;
        int solved = 0;
        int ones = 0;
        int twos = 0;
        for(int i = 1; i <= LT / L1 && solved < 2; i++) {
            if((LT - (i*L1)) % L2 == 0) {
                int robot2s = (LT - (i*L1)) / L2;
                if(AT - i*A1 - robot2s*A2 == 0 && robot2s >= 1) {
                    ones = i;
                    twos = robot2s;
                    solved++;
                }
            }
        }
        if(solved != 1) {
            cout << "?" << endl;
        }
        else {
            cout << ones << " " << twos << endl;
        }
    }
    
    return 0;
}
