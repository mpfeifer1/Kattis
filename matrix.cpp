#include <iostream>

using namespace std;

int main() {
    long long a, b, c, d;
    int count = 1;
    while(cin >> a && cin >> b && cin >> c && cin >> d) {
        cout << "Case " << count << ":" << endl;
        count++;

        long long denom = (a*d) - (b*c);

        cout << d / denom << " " << -b / denom << endl;
        cout << -c / denom << " " << a / denom << endl;
    }
}
