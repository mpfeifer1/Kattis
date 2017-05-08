#include <iostream>
#include <vector>
#include <string>

using namespace std;

string getWord(int n) {
    if(n == 0) {
        return "none";
    }
    if(n == 1) {
        return "one";
    }
    if(n == 2) {
        return "both";
    }
    return "one";
}

int main() {
    int a1, c1, a2, c2;
    cin >> a1 >> c1 >> a2 >> c2;

    int t1, t2, t3;
    cin >> t1 >> t2 >> t3;

    vector<int> v;
    v.resize(1002, 0);

    bool mad1 = true;
    bool mad2 = true;
    int time1 = 0;
    int time2 = 0;
    for(int i = 1; i < v.size(); i++) {
        if(mad1) {
            v[i]++;
        }
        if(mad2) {
            v[i]++;
        }

        time1++;
        time2++;


        bool toggled1 = false;
        bool toggled2 = false;

        if(mad1 && time1==a1) {
            mad1 = false;
            time1 = 0;
            toggled1 = true;
        }
        if(!mad1 && time1==c1 && !toggled1) {
            mad1 = true;
            time1 = 0;
        }
        if(mad2 && time2==a2) {
            mad2 = false;
            time2 = 0;
            toggled2 = true;
        }
        if(!mad2 && time2==c2 && !toggled2) {
            mad2 = true;
            time2 = 0;
        }
    }

    cout << getWord(v[t1]) << endl;
    cout << getWord(v[t2]) << endl;
    cout << getWord(v[t3]) << endl;
}
