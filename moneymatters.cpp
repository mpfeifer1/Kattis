#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

// Find parent in disjoint set
ll find(vector<ll>& disjoint, ll a) {
    if(disjoint[a] == -1) {
        return a;
    }

    ll tmp = find(disjoint, disjoint[a]);
    disjoint[a] = tmp;
    return tmp;
}

// Join two people in disjoint set
void join(vector<ll>& disjoint, ll a, ll b) {
    a = find(disjoint, a);
    b = find(disjoint, b);

    if(a == b) {
        return;
    }

    disjoint[b] = a;
}

int main() {
    ll people, friendships;
    cin >> people >> friendships;

    // Allocate memory
    vector<ll> disjoint(people, -1);
    vector<ll> debts(people, 0);
    vector<ll> grouptotal(people, 0);

    // Read in all debts
    for(ll i = 0; i < people; i++) {
        cin >> debts[i];
    }

    // Read in all friendships
    ll f1, f2;
    for(ll i = 0; i < friendships; i++) {
        cin >> f1 >> f2;
        join(disjoint, f1, f2);
    }

    // Calculate all group debts
    for(ll i = 0; i < people; i++) {
        grouptotal[find(disjoint, i)] += debts[i];
    }

    // Check if there's a nonzero group debt
    for(auto i : grouptotal) {
        if(i != 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    cout << "POSSIBLE" << endl;
}
