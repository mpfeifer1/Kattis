#include <iostream>
#include <deque>

using namespace std;

int main() {
    char input;
    deque<char> q;
    while(cin >> input) {
        if(input == '<') {
            q.pop_back();
        }
        else {
            q.push_back(input);
        }
    }
    while(!q.empty()) {
        cout << q.front();
        q.pop_front();
    }
    cout << endl;
}
