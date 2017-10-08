#include <unordered_set>
#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

int main() {
    int cases;
    cin >> cases;

    for(int i = 0; i < cases; i++) {
        int n;
        cin >> n;

        deque<int> q;
        unordered_set<int> s;
        int total = 0;
        for(int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            if(s.count(temp) > 0) {
                while(q.front() != temp) {
                    s.erase(q.front());
                    q.pop_front();
                }
                q.pop_front();
                q.push_back(temp);
            }
            else {
                q.push_back(temp);
                s.insert(temp);
                total = max(total, int(q.size()));
            }
        }

        cout << total << endl;
    }
}
