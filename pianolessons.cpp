#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct BipartiteMatcher {
    vector<vector<int>> G;
    vector<int> L, R, Viz;

    BipartiteMatcher(int n, int m) :
        G(n), L(n, -1), R(m, -1), Viz(n) {}

    void AddEdge(int a, int b) {
        G[a].push_back(b);
    }

    bool Match(int node) {
        if(Viz[node])
            return false;
        Viz[node] = true;

        for(auto vec : G[node]) {
            if(R[vec] == -1 || Match(R[vec])) {
                L[node] = vec;
                R[vec] = node;
                return true;
            }
        }

        return false;
    }
    int Solve() {
        bool ok = true;
        while(ok) {
            ok = false;
            fill(Viz.begin(), Viz.end(), 0);
            for(int i = 0; i < L.size(); ++i)
                if(L[i] == -1)
                    ok |= Match(i);
        }

        int ret = 0;
        for(int i = 0; i < L.size(); ++i)
            ret += (L[i] != -1);
        return ret;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    BipartiteMatcher bm(n, m);
    for(int i = 0; i < n; ++i) {
        int size;
        cin >> size;
        for(int j = 0; j < size; ++j) {
            int slot;
            cin >> slot;
            bm.AddEdge(i, slot-1);
        }
    }
    cout << bm.Solve() << '\n';
}
