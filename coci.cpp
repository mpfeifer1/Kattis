#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Fenwick {
    vector<ll> tree;
    Fenwick(int n) {
        tree.resize(n,0);
    }
    Fenwick(const vector<ll>& val) {
        tree.resize(val.size(),0);
        for(int i = 0; i < val.size(); i++) {
            increase(i, val[i]);
        }
    }
    void increase(int i, ll d) {
        for(; i<tree.size(); i |= i+1) tree[i] += d;
    }
    ll sum(int i) {
        ll s = 0;
        for(; i > 0; i &= i-1) s += tree[i-1];
        return s;
    }
    // [l,r)
    ll sum(int l, int r) {
        return sum(r) - sum(l);
    }
};

struct people {
    int pos;
    int round1;
    int round2;

    int worse;
    int better;
};

bool cmp(people& p1, people& p2) {
    if(p1.round1 == p2.round1) {
        return p1.round2 > p2.round2;
    }
    return p1.round1 < p2.round1;
}

bool cmp2(people& p1, people& p2) {
    return p1.pos < p2.pos;
}

void solve(vector<people>& p, bool strictlygreater) {
    Fenwick f(652);

    for(int i = 0; i < p.size(); i++) {
        if(strictlygreater) {
            p[i].better = f.sum(p[i].round2+1, 651);
            f.increase(p[i].round2, 1);
        }
        else {
            p[i].worse = f.sum(p[i].round2);
            f.increase(p[i].round2, 1);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<people> p(n);

    for(int i = 0; i < n; i++) {
        p[i].pos = i;
        cin >> p[i].round1 >> p[i].round2;
    }

    sort(p.begin(), p.end(), cmp);
    solve(p, false);

    for(auto& i : p) {
        i.round1 *= -1;
        i.round2 *= -1;
    }
    sort(p.begin(), p.end(), cmp);
    for(auto& i : p) {
        i.round1 *= -1;
        i.round2 *= -1;
    }

    solve(p, true);

    map<int,int> cnts1;
    map<int,int> cnts2;

    for(auto& i : p) {
        if(i.round1 == 0) {
            cnts1[i.round2]++;
        }
        if(i.round2 == 0) {
            cnts2[i.round1]++;
        }
    }

    int zeros = 0;
    for(auto& i : p) {
        if(i.round1 == 650) {
            i.worse += cnts1[i.round2];
        }
        if(i.round2 == 650) {
            i.worse += cnts2[i.round1];
        }
    }

    sort(p.begin(), p.end(), cmp2);
    for(auto i : p) {
        cout << (i.better+1) << " " << (p.size() - i.worse) << endl;
    }
}

