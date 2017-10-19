#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int h1, m1, s1;
    int h2, m2, s2;

    cin >> h1;
    cin.ignore();
    cin >> m1;
    cin.ignore();
    cin >> s1;

    cin >> h2;
    cin.ignore();
    cin >> m2;
    cin.ignore();
    cin >> s2;

    if(s2 < s1) {
        s2 += 60;
        m2 -= 1;
    }

    if(m2 < m1) {
        m2 += 60;
        h2 -= 1;
    }

    if(h2 < h1) {
        h2 += 24;
    }

    h2 -= h1;
    m2 -= m1;
    s2 -= s1;

    if(h2 == 0 && m2 == 0 && s2 == 0) {
        h2 += 24;
    }

    cout << setfill('0') << setw(2);
    cout << h2 << ":";
    cout << setfill('0') << setw(2);
    cout << m2 << ":";
    cout << setfill('0') << setw(2);
    cout << s2 << endl;
}
