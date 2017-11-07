#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct node {
    bool visited;
    int degree;
    vector<int> neighbors;
};

void removeleaves(vector<node>& v) {
    // Create stack
    stack<int> s;

    // Find all with degree 1
    for(int i = 0; i < v.size(); i++) {
        if(v[i].degree == 1) {
            s.push(i);
        }
    }

    // Remove all with degree 1
    while(!s.empty()) {
        int curr = s.top();
        s.pop();

        v[curr].visited = true;
        for(int i = 0; i < v[curr].neighbors.size(); i++) {
            int neighbor = v[curr].neighbors[i];
            if(!v[neighbor].visited) {
                v[neighbor].degree--;
                if(v[neighbor].degree == 1) {
                    s.push(neighbor);
                }
                cout << curr << " " << neighbor << endl;
            }
        }
    }

}

void removecycles(vector<node>& v, int start) {
    stack<int> s;
    s.push(start);

    while(!s.empty()) {
        int curr = s.top();
        s.pop();

        for(int i = 0; i < v[curr].neighbors.size(); i++) {
            int neighbor = v[curr].neighbors[i];
            if(!v[neighbor].visited) {
                s.push(neighbor);
                v[curr].visited = true;
                cout << curr << " " << neighbor << endl;
                break;
            }
        }
    }

    // Reattach cycle
    for(int i = 0; i < v[start].neighbors.size(); i++) {
        int neighbor = v[start].neighbors[i];
        if(!v[neighbor].visited) {
            cout << neighbor << " " << start << endl;
            break;
        }
    }
}

int main() {
    int n;
    cin >> n;

    node empty = {false, 0, {}};
    vector<node> v(n+2, empty);

    // Read in input, store into graph
    for(int i = 0; i < n; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        v[n1].neighbors.push_back(n2);
        v[n2].neighbors.push_back(n1);

        v[n1].degree++;
        v[n2].degree++;
    }
    n++;


    // Remove leaves
    removeleaves(v);

    // Remove any extra cycles
    for(int i = 1; i < n+1; i++) {
        if(!v[i].visited) {
            removecycles(v, i);
        }
    }
}
