#include <unordered_map>
#include <iostream>
#include <deque>

using namespace std;

int main() {
    unordered_map<char, char> m;
    m['R'] = 'S';
    m['B'] = 'K';
    m['L'] = 'H';

    deque<char> q;
    char c;
    while(cin >> c) {
        q.push_back(c);
    }

    while(!q.empty()) {
        if(q.size() >= 3 && q[0] != q[1] && q[1] != q[2] && q[0] != q[2]) {
            q.pop_front();
            q.pop_front();
            q.pop_front();
            cout << "C";
        }
        else {
            cout << m[q.front()];
            q.pop_front();
        }
    }
    cout << endl;
}
