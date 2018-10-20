#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int inf = 1 << 30;
#define umap unordered_map

vector<int> allfactors;
void sieve() {
    vector<bool> p(100000, true);
    p[0] = false;
    p[1] = false;
    for(int i = 2; i < p.size(); i++) {
        if(p[i]) {
            allfactors.push_back(i);
            for(int j = i+i; j < p.size(); j += i) {
                p[j] = false;
            }
        }
    }
}

vector<int> factorize(int val) {
    vector<int> factors;
    for(auto i : allfactors) {
        if(i * i > val) {
            break;
        }
        if(val % i == 0) {
            factors.push_back(i);
            while(val % i == 0) {
                val /= i;
            }
        }
    }
    if(val > 1) {
        factors.push_back(val);
    }
    return factors;
}

int n;
vector<int> v;
vector<int> par;
umap<int, set<int>> factoridx;
vector<vector<int>> factors;

pair<int,int> get(int factor, int index) {
    pair<int,int> ret;

    auto it = factoridx[factor].find(index);
    if(it == factoridx[factor].begin()) {
        ret.first = -inf;
    }
    else {
        ret.first = *prev(it);
    }

    it = next(it);
    if(it == factoridx[factor].end()) {
        ret.second = inf;
    }
    else {
        ret.second = *it;
    }

    return ret;
}

// [start, end]
bool solve(int start, int end, int prev) {
    if(start > end) {
        return true;
    }
    if(start == end) {
        par[start] = prev;
        return true;
    }

    int times = end - start + 1;
    for(int i = 0; i < times; i++) {
        int curr;
        if(i % 2 == 0) {
            curr = start + (i / 2);
        }
        else {
            curr = end - (i / 2);
        }

        bool works = true;
        for(auto& j : factors[curr]) {
            pair<int,int> p = get(j, curr);
            if(p.first >= start) {
                works = false;
                break;
            }
            if(p.second <= end) {
                works = false;
                break;
            }
        }

        if(works) {
            par[curr] = prev;
            return solve(start, curr-1, curr) && solve(curr+1, end, curr);
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    sieve();

    cin >> n;
    v.resize(n+1);
    par.resize(n+1);
    factors.resize(n+1);

    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        vector<int> s = factorize(v[i]);
        factors[i] = s;
        for(auto& j : s) {
            factoridx[j].insert(i);
        }
    }

    if(solve(1, n, 0)) {
        for(int i = 1; i <= n; i++) {
            cout << par[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "impossible" << endl;
    }
}
