#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;


    int t = 0, c = 0, g = 0;
    for(auto a : s) {
        if(a == 'C') {
            c++;
        }
        if(a == 'T') {
            t++;
        }
        if(a == 'G') {
            g++;
        }
    }

    int sum = min(min(t, c), g) * 7;
    sum += (t*t)+(c*c)+(g*g);

    cout << sum << endl;
}
