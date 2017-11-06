#include <unordered_set>
#include <iostream>

using namespace std;

int main() {
    int start1, start2;
    cin >> start1 >> start2;

    int size;

    cin >> size;
    unordered_set<int> times1;
    for(int i = 0; i < size; i++) {
        int temp;
        cin >> temp;
        times1.insert(temp);
    }

    cin >> size;
    unordered_set<int> times2;
    for(int i = 0; i < size; i++) {
        int temp;
        cin >> temp;
        times2.insert(temp);
    }

    if(start1 > start2) {
        swap(start1, start2);
        swap(times1, times2);
    }

    int t1 = start1;
    int t2 = start2;

    bool driving1 = false;
    bool driving2 = false;
    for(int i = 0; i < 10000000; i++) {
        if(driving1) {
            t1++;
        }
        if(driving2) {
            t2++;
        }

        if(times1.count(i) > 0) {
            driving1 = !driving1;
        }
        if(times2.count(i) > 0) {
            driving2 = !driving2;
        }

        if(t2 - t1 <= 4) {
            cout << "bumper tap at time " << i << endl;
            return 0;
        }
    }

    cout << "safe and sound" << endl;
}
