#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;

    double w = 0;
    double l = 0;
    double u = 0;
    double s = 0;

    cout.precision(10);

    for(auto c : str) {
        if(c == '_') {
            w++;
        }
        else if(islower(c)) {
            l++;
        }
        else if(isupper(c)) {
            u++;
        }
        else {
            s++;
        }
    }

    int len = str.length();
    cout << w/len << endl;
    cout << l/len << endl;
    cout << u/len << endl;
    cout << s/len << endl;
}
