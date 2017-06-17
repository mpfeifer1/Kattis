#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int n;

    while(cin >> n) {
        // Set up initial conditions
        priority_queue<int> p;
        queue<int> q;
        stack<int> s;

        bool broken = false;
        int count = 0;

        bool isP = true;
        bool isQ = true;
        bool isS = true;

        int i, op, num;
        for(i = 0; i < n; i++) {
            // Take in query
            cin >> op >> num;

            // Insert
            if(op == 1) {
                p.push(num);
                q.push(num);
                s.push(num);

                count++;
            }

            // Remove
            else {
                if(count == 0) {
                    cout << "impossible" << endl;
                    broken = true;
                    break;
                }

                if(p.top() != num) {
                    isP = false;
                }
                if(q.front() != num) {
                    isQ = false;
                }
                if(s.top() != num) {
                    isS = false;
                }


                p.pop();
                q.pop();
                s.pop();

                count--;
            }
        }

        if(broken) {
            for(i++; i < n; i++) {
                cin >> op >> num;
            }
            continue;
        }

        int trues = 0;
        if(isP) {
            trues++;
        }
        if(isQ) {
            trues++;
        }
        if(isS) {
            trues++;
        }

        if(trues > 1) {
            cout << "not sure" << endl;
        }
        if(trues == 1) {
            if(isP) {
                cout << "priority queue" << endl;
            }
            if(isQ) {
                cout << "queue" << endl;
            }
            if(isS) {
                cout << "stack" << endl;
            }
        }
        if(trues < 1) {
            cout << "impossible" << endl;
        }
    }
}
