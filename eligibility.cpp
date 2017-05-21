#include <iostream>
#include <string>

using namespace std;

int main() {
    int num;
    cin >> num;

    for(int i = 0; i < num; i++) {
        string name;
        string school;
        string age;
        int courses;

        cin >> name >> school >> age;
        cin >> courses;

        bool elgible = true;

        cout << name << " ";

        if(school >= "2010/00/00") {
            cout << "eligible" << endl;
            continue;
        }

        if(age >= "1991/00/00") {
            cout << "eligible" << endl;
            continue;
        }

        if(courses > 40) {
            cout << "ineligible" << endl;
            continue;
        }

        cout << "coach petitions" << endl;
    }
}
