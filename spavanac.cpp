#include <iostream>

using namespace std;

int main() {
    int hour, min;
    cin >> hour >> min;

    hour--;
    min += 15;

    if(hour < 0) {
        hour += 24;
    }

    if(min >= 60) {
        min -= 60;
        hour++;
    }

    cout << hour << " " << min << endl;
}
