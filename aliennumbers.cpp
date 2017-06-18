#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int getValue(char s, string& source) {
    for(int i = 0; i < source.size(); i++) {
        if(source[i] == s) {
            return i;
        }
    }

    return 0;
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Case #" << i+1 << ": ";

        string number, source, target;
        cin >> number >> source >> target;

        int sizeS = source.length();
        int sizeT = target.length();

        reverse(number.begin(), number.end());

        long long representation = 0;
        for(int j = 0; j < number.size(); j++) {
            representation += getValue(number[j], source) * pow(sizeS, j);
        }

        string ret = "";
        while(representation > 0) {
            ret += target[representation % sizeT];
            representation /= sizeT;
        }

        reverse(ret.begin(), ret.end());

        cout << ret << endl;
    }
}
