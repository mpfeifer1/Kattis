#include <iostream>

using namespace std;

int main() {
    long int num, div;
    while(cin >> num >> div) {
        if(num == 0 && div == 0) {
            return 0;
        }
        cout << num / div << " " << num % div << " / " << div << endl;
    }
}
