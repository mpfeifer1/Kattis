#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void incrementplate(string& s) {
    if(s[2] == 'Z') {
        s[2] = 'A';
        if(s[1] == 'Z') {
            s[1] = 'A';
            if(s[0] == 'Z') {
                s[0] = 'A';
            }
            else {
                s[0]++;
            }
        }
        else {
            s[1]++;
        }
    }
    else {
        s[2]++;
    }
}

bool isprime(int n) {
    if(n < 2) {
        return false;
    }
    if(n == 2) {
        return true;
    }

    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    int n;
    while(cin >> s && cin >> n && !(s == "END" && n == 0)) {
        while(!isprime(n)) {
            n++;
            if(n == 10000) {
                incrementplate(s);
                n = 2;
                break;
            }
        }

        cout << setfill('0');
        cout << s << " " << setw(4) << n << endl;
    }
}
