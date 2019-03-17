#include <bits/stdc++.h>

using namespace std;

void rotate(deque<pair<int,int>>& p) {
    int w = 0;
    for(auto i : p) {
        w = max(w,i.first);
    }

    for(auto& i : p) {
        pair<int,int> t = {i.second,w-i.first};
        i = t;
    }
}

void compress(deque<pair<int,int>>& p) {
    vector<int> x;
    vector<int> y;

    for(auto i : p) {
        x.push_back(i.first);
        y.push_back(i.second);
    }

    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    x.erase(unique(x.begin(),x.end()),x.end());
    y.erase(unique(y.begin(),y.end()),y.end());

    map<int,int> convx;
    map<int,int> convy;

    for(int i = 0; i < x.size(); i++) {
        convx[x[i]] = i;
    }

    for(int i = 0; i < y.size(); i++) {
        convy[y[i]] = i;
    }

    for(auto& i : p) {
        i.first = convx[i.first];
        i.second = convy[i.second];
    }
}

bool equal(deque<pair<int,int>>& d1, deque<pair<int,int>>& d2) {
    for(int i = 0; i < d2.size(); i++) {
        if(d1 == d2) return true;
        d2.push_front(d2.back());
        d2.pop_back();
    }
    return false;
}

int main() {
    int n1;
    cin >> n1;
    deque<pair<int,int>> p1(n1);
    for(auto& i : p1) {
        cin >> i.first >> i.second;
    }

    int n2;
    cin >> n2;
    deque<pair<int,int>> p2(n2);
    for(auto& i : p2) {
        cin >> i.first >> i.second;
    }

    if(n1 != n2) {
        cout << "no" << endl;
        return 0;
    }

    compress(p1);
    compress(p2);

    if(equal(p1,p2)) {
        cout << "yes" << endl;
        return 0;
    }
    rotate(p2);
    if(equal(p1,p2)) {
        cout << "yes" << endl;
        return 0;
    }
    rotate(p2);
    if(equal(p1,p2)) {
        cout << "yes" << endl;
        return 0;
    }
    rotate(p2);
    if(equal(p1,p2)) {
        cout << "yes" << endl;
        return 0;
    }

    cout << "no" << endl;
}
