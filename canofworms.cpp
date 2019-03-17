#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct SegmentTree {
    vector<ll> treeMin, treeMax;
    ll n, root, size;
    SegmentTree(int currSize) : n(currSize), root(1) {
        ll x = (ll)(ceil(log2(currSize)));
        size = 2*(ll)pow(2, x);
        treeMax.resize(size, 0);
        treeMin.resize(size, 1e16);
    }
    void update(int l, ll diff) {update(root, 0, n-1, l, diff);}
    void update(int node, int start, int end, int l, ll diff) {
        if(start > end || start > l || end < l) return;
        if(start >= l && end <= l) {
            treeMax[node] = diff;
            treeMin[node] = diff;
            return;
        }
        ll mid = (start + end) / 2;
        update(2*node, start, mid, l, diff);
        update(2*node+1, mid+1, end, l, diff);
        treeMax[node] = max(treeMax[2*node], treeMax[2*node+1]);
        treeMin[node] = min(treeMin[2*node], treeMin[2*node+1]);
    }
    ll queryMax(int l, int r) {return queryMax(root, 0, n-1, l, r);}
    ll queryMax(int node, int start, int end, int l, int r) {
        if(r < start || end < l) return -1e16;
        if(l <= start && end <= r) return treeMax[node];
        ll mid = (start+end)/2;
        return max(queryMax(2*node, start, mid, l, r), queryMax(2*node+1, mid+1, end, l, r));
    }
    ll queryMin(int l, int r) {return queryMin(root, 0, n-1, l, r);}
    ll queryMin(int node, int start, int end, int l, int r) {
        if(r < start || end < l) return 1e16;
        if(l <= start && end <= r) return treeMin[node];
        ll mid = (start+end)/2;
        return min(queryMin(2*node, start, mid, l, r), queryMin(2*node+1, mid+1, end, l, r));
    }
};

struct can {
    int x, r, i;
};

bool cmpL(const can &i, const can &j) {
    if(i.x-i.r == j.x-j.r) {
        return i.x < j.x;
    }
    return i.x-i.r < j.x-j.r;
}

bool cmpR(const can &i, const can &j) {
    if(i.x+i.r == j.x+j.r) {
        return i.x > j.x;
    }
    return i.x+i.r < j.x+j.r;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> compress;
    compress.reserve(3*n);
    vector<can> arr(n);
    vector<int> X(n);
    for(int i = 0; i < n; ++i) {
        int x, r;
        cin >> x >> r;
        X[i] = x;
        arr[i] = {x,r,i};
        compress.push_back(x);
        compress.push_back(x+r);
        compress.push_back(x-r);
    }
    sort(X.begin(), X.end());
    sort(compress.begin(), compress.end());
    compress.erase(unique(compress.begin(), compress.end()), compress.end());
    vector<ll> Left(n);
    vector<ll> Right(n);
    for(int i = 0; i < n; ++i) {
        Left[i] = (lower_bound(compress.begin(), compress.end(), arr[i].x-arr[i].r) - compress.begin());
        Right[i] = (lower_bound(compress.begin(), compress.end(), arr[i].x+arr[i].r) - compress.begin());
    }
    for(int l = 0; l < 10; ++l) {
        sort(arr.begin(), arr.end(), cmpR);
        SegmentTree st(compress.size()+10);
        for(int i = (int)arr.size()-1; i >= 0; --i) {
             ll farRight = Right[arr[i].i];
             int currL = Left[arr[i].i];
             int currR = Right[arr[i].i];
             int currX = (lower_bound(compress.begin(), compress.end(), arr[i].x) - compress.begin());
             farRight = max((ll)farRight, st.queryMax(currL, currR));
             st.update(currX, farRight);
             Right[arr[i].i] = farRight;
        }
        sort(arr.begin(), arr.end(), cmpL);
        SegmentTree st2(compress.size()+10);

        for(int i = 0; i < n; ++i) {
            ll farLeft = Left[arr[i].i];
            int currL = Left[arr[i].i];
            int currR = Right[arr[i].i];
            int currX = (lower_bound(compress.begin(), compress.end(), arr[i].x) - compress.begin());
            farLeft = min((ll)farLeft, st2.queryMin(currL, currR));
            st2.update(currX, farLeft);
            Left[arr[i].i] = farLeft;
        }
    }
    for(int i = 0; i < n; ++i) {
        cout << (upper_bound(X.begin(), X.end(), compress[Right[i]]) - lower_bound(X.begin(), X.end(), compress[Left[i]])) << ' ';
    }
    cout << '\n';
}
