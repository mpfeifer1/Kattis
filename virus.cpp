#include <iostream>
#include <list>

using namespace std;

int main() {
    list<char> l1, l2;

    // Take in Data
    char c;
    while(cin.get(c) && c != '\n') {
        l1.push_back(c);
    }
    while(cin.get(c) && c != '\n') {
        l2.push_back(c);
    }

    // Remove beginning items
    while(!l1.empty() && !l2.empty() && l1.front() == l2.front()) {
        l1.pop_front();
        l2.pop_front();
    }

    // Remove ending items
    while(!l1.empty() && !l2.empty() && l1.back() == l2.back()) {
        l1.pop_back();
        l2.pop_back();
    }

    // Print answer
    cout << l2.size() << endl;
}
