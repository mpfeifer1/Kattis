#include <bits/stdc++.h>

using namespace std;

int find(vector<int>& d, int a) {
    if(d[a] == -1) return a;
    return d[a] = find(d, d[a]);
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);
    if(a == b) return;
    d[a] = b;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> d(n,-1);
    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;
        join(d,n1,n2);
    }

    bool works = true;
    for(int i = 0; i < n; i++) {
        if(find(d,i) != find(d,n-i-1)) works = false;
    }

    if(works) cout << "Yes" << endl;
    else cout << "No" << endl;
}
