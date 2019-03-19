#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef long long ll;

const int MAXN = 1e5+10;
string s;
int N, gap;
int sa[MAXN], pos[MAXN], lcp[MAXN], tmp[MAXN];

bool sufCmp(int i, int j) {
    if(pos[i] != pos[j]) return pos[i] < pos[j];
    i += gap;
    j += gap;
    return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}

void buildSA() {
    N = s.length();
    for(int i = 0; i < N; ++i) {
        sa[i] = i;
        pos[i] = s[i];
    }
    for(gap = 1;; gap *= 2) {
        sort(sa, sa + N, sufCmp);
        for(int i = 0; i < N-1; ++i)
            tmp[i+1] = tmp[i] + sufCmp(sa[i], sa[i+1]);
        for(int i = 0; i < N; ++i) pos[sa[i]] = tmp[i];
        if(tmp[N-1] == N-1) break;
    }
}

void buildLCP() {
    N = s.size();
    for(int i = 0, k = 0; i < N; ++i) {
        if(pos[i] != 0 ) {
            for(int j = sa[pos[i]-1]; s[i+k] == s[j+k];) k++;
            lcp[pos[i]] = k;
            if(k) k--;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;

    buildSA();
    buildLCP();

    int bestval = -1;
    int bestidx = -1;

    for(int i = 0; i < s.size(); i++) {
        if(lcp[i] > bestval) {
            bestval = lcp[i];
            bestidx = sa[i];
        }
    }

    for(int i = 0; i < bestval; i++) {
        cout << s[bestidx+i];
    }
    cout << endl;
}
