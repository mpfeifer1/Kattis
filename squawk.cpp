#include <iostream>
#include <vector>

using namespace std;

struct Node {
    vector<Node*> f; // Friends
    unsigned long long squawks = 0;
    unsigned long long squawksIn = 0;
};

int main() {

    int users, links, start, time;
    vector<Node*> u; // Users
    cin >> users >> links >> start >> time;
    int x, y;

    if(users <= 1 || time <= 0 || links == 0) {
        cout << '0' << endl;
        return 0;
    }

    for(int i = 0; i < users; i++)
    {
        Node* n = new Node;
        n->squawks = 0;
        u.push_back(n);
    }

    for(int i = 0; i < links; i++) {
        cin >> x >> y;
        u[x]->f.push_back(u[y]);
        u[y]->f.push_back(u[x]);
    }

    u[start]->squawks++;

    for(int t = 1; t <= time; t++) {
        unsigned long long squawksSent = 0;
        // Send out squawks
        for(int i = 0; i < users; i++) {
            for(int j = 0; j < u[i]->f.size(); j++) {
                u[i]->f[j]->squawksIn+=u[i]->squawks;
                squawksSent += u[i]->squawks;
            }
        }

        // Recieve squawks
        for(int i = 0; i < users; i++) {
            u[i]->squawks = u[i]->squawksIn;
            u[i]->squawksIn = 0;
        }

        if(t == time) {
            cout << squawksSent << endl;
        }
    }
}

