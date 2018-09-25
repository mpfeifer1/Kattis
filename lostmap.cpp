#include <algorithm>
#include <set>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct edge {
    int n1;
    int n2;
    int dist;
};

bool cmp(edge& lhs, edge& rhs) {
    return lhs.dist < rhs.dist;
}

int find(vector<int>& d, int a) {
    if(d[a] < 0) return a;
    return d[a] = find(d, d[a]);
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);
    if(a == b) return;
    if(d[a] > d[b]) {
        swap(a,b);
    }
    d[a] += d[b];
    d[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int v;
    cin >> v;

    vector<edge> e;
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            int num;
            cin >> num;
            if(i > j) {
                e.push_back({i, j, num});
            }
        }
    }

    sort(e.begin(), e.end(), cmp);

    vector<int> d(v, -1);

    for(auto i : e) {
        int n1 = find(d, i.n1);
        int n2 = find(d, i.n2);
        if(n1 != n2) {
            cout << i.n1 + 1 << " " << i.n2 + 1 << endl;
            join(d, n1, n2);
        }
    }
}
