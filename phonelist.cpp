#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node {
    bool ending = false;
    vector<node*> v;
};

bool insert(node* start, string num) {
    // Setup
    int to_insert = num[num.size()-1] - '0';

    // Check existence
    bool exists = start->v[to_insert] != nullptr;
    if(exists) {
        // If we're setting something to an ending, return false
        if(num.size() == 1) {
            return false;
        }

        // If not valid, return
        if(start->v[to_insert]->ending) {
            return false;
        }

        // If valid, insert next character
        num.pop_back();
        return insert(start->v[to_insert], num);
    }

    // Insert character
    node* n = new node;
    n->ending = false;
    n->v.resize(10, nullptr);
    start->v[to_insert] = n;

    // Check if inserting last character
    if(num.size() == 1) {
        n->ending = true;
        return true;
    }

    // Inesrt the rest
    num.pop_back();
    return insert(start->v[to_insert], num);
}

int main() {
    int cases;
    cin >> cases;

    for(int i = 0; i < cases; i++) {
        node* start = new node;
        start->ending = false;
        start->v.resize(10, nullptr);

        int numbers;
        cin >> numbers;

        bool valid = true;

        for(int j = 0; j < numbers; j++) {
            string num;
            cin >> num;
            reverse(num.begin(), num.end());

            valid &= insert(start, num);
        }

        if(valid) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
