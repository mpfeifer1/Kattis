#include <iostream>
#include <string>

using namespace std;

int main() {
    string month, day, year;
    int hour1, minute1, hour2, minute2;
    while(cin >> month && cin >> day && cin >> year) {
        cin >> hour1;
        cin.ignore();
        cin >> minute1;

        cin >> hour2;
        cin.ignore();
        cin >> minute2;

        cout << month << " " << day << " " << year << " ";

        int hours = hour2 - hour1;
        int minutes = minute2 - minute1;

        if(minutes < 0) {
            minutes += 60;
            hours--;
        }

        cout << hours << " hours " << minutes << " minutes" << endl;
    }
}
