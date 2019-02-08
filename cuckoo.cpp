#include <bits/stdc++.h>

using namespace std;

map<int,int> reinserted;
vector<int> current;
vector<pair<int,int>> hashes;

bool swap(int n, int old) {
    reinserted[n]++;
    if(reinserted[n] >= 3) {
        return false;
    }

    int val;
    if(hashes[n].first == old) {
        val = hashes[n].second;
    }
    else {
        val = hashes[n].first;
    }

    if(current[val] == -1) {
        current[val] = n;
        return true;
    }
    else {
        int temp = current[val];
        current[val] = n;
        return swap(temp,val);
    }
}

bool insert(int n) {
    if(current[hashes[n].first] == -1) {
        current[hashes[n].first] = n;
        return true;
    }
    else if(current[hashes[n].second] == -1) {
        current[hashes[n].second] = n;
        return true;
    }
    else {
        int temp = current[hashes[n].first];
        current[hashes[n].first] = n;
        return swap(temp,hashes[n].first);
    }
}

void solve() {
    reinserted.clear();
    hashes.clear();
    current.clear();

    int n, m;
    cin >> m >> n;

    hashes.resize(m);
    current.resize(n,-1);

    // Read in the input
    for(int i = 0; i < m; i++) {
        cin >> hashes[i].first;
        cin >> hashes[i].second;
    }

    bool works = true;
    for(int i = 0; i < m; i++) {
        if(!insert(i)) {
            works = false;
            break;
        }
        reinserted.clear();
    }

    if(works) {
        cout << "successful hashing" << endl;
    }
    else {
        cout << "rehash necessary" << endl;
    }
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
