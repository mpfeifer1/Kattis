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

struct sparseTable {
    vector<vector<ll> > memo;
    vector<int> logTwo;
    int maxPow;
    sparseTable(vector<ll> &arr) {
        int n = arr.size();
        logTwo.resize(n+1,0);
        for(int i = 2; i <= n; ++i) logTwo[i] = 1 + logTwo[i/2];
        maxPow = logTwo[n]+1;
        memo.resize(maxPow, vector<ll>(n));
        for(int j = 0; j < maxPow; ++j) {
            for(int i = 0; i < n; ++i) {
                if(i+(1<<j)-1<n) {
                    memo[j][i] = (j?min(memo[j-1][i], memo[j-1][i+(1<<(j-1))]):arr[i]);
                } else break;
            }
        }
    }
    ll query(int l, int r) {
        if(l > r) return 0;
        int j = logTwo[r-l+1];
        return min(memo[j][l], memo[j][r-(1<<j)+1]);
    }
};


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    buildSA();
    vector<int> inv(s.size());
    for(int i = 0; i < s.size(); ++i) {
        inv[sa[i]] = i;
    }
    buildLCP();
    vector<int> temp(s.size());
    for(int i = 0; i < s.size(); ++i) {
        temp[i] = lcp[i];
    }
    sparseTable st(temp);
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i) {
        int pos1, pos2;
        cin >> pos1 >> pos2;
        pos1 = inv[pos1];
        pos2 = inv[pos2];
        if(pos1 > pos2) swap(pos1,pos2);
        cout << st.query(pos1+1, pos2) << '\n';
    }
}
