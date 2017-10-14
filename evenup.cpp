#include <iostream>
#include <list>

using namespace std;

int main() {
    int items;
    cin >> items;

    list<int> l;
    for(int i = 0; i < items; i++) {
        int temp;
        cin >> temp;
        l.push_back(temp % 2);
    }

    auto it = l.begin();
    while(it != l.end() && l.size() >= 2) {
        // If same, remove
        if(*it == *next(it)) {
            if(it != l.begin()) {
                it = prev(it);
                l.erase(next(it));
                l.erase(next(it));
            }
            else if(next(it) != l.end()) {
                it = next(next(it));
                l.erase(prev(it));
                l.erase(prev(it));
            }
            else {
                l.erase(next(it));
                l.erase(it);
                break;
            }
        }

        // Otherwise, advance
        else {
            it = next(it);
        }
    }

    cout << l.size() << endl;
}
