#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct SegmentTree {
    vector<ll> treeSum, treeMax, lazy;
    ll n, root, size;
    SegmentTree(int currSize) : n(currSize), root(1) {
        ll x = (ll)(ceil(log2(currSize)));
        size = 2*(ll)pow(2, x);
        treeSum.resize(size, 0);
        treeMax.resize(size, 0);
        lazy.resize(size, 0);
    }
    SegmentTree(const vector<ll> &arr) : n(arr.size()), root(1) {
        ll x = (ll)(ceil(log2(n)));
        size = 2*(ll)pow(2, x);
        treeSum.resize(size);
        treeMax.resize(size);
        lazy.resize(size, 0);
        build(arr, root, 0, n-1);
    }
    void build(const vector<ll> &arr, int node, int start, int end) {
        if(start == end) treeMax[node] = treeSum[node] = arr[start];
        else {
            ll mid = (start+end)/2;
            build(arr, 2*node, start, mid);
            build(arr, 2*node+1, mid+1, end);
            treeSum[node] = treeSum[2*node] + treeSum[2*node+1];
            treeMax[node] = max(treeMax[2*node], treeMax[2*node+1]);
        }
    }
    void pendingUpdate(int node, int start, int end) {
        if(lazy[node]) {
            treeSum[node] += (end-start+1) * lazy[node];
            treeMax[node] += lazy[node];
            if(start != end) {
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    void updateRange(int l, int r, ll diff) {updateRange(root, 0, n-1, l, r, diff);}
    void updateRange(int node, int start, int end, int l, int r, ll diff) {
        pendingUpdate(node, start, end);
        if(start > end || start > r || end < l) return;
        if(start >= l && end <= r) {
            treeSum[node] += (end-start+1) * diff;
            treeMax[node] += diff;
            if(start != end) {
                lazy[2*node] += diff;
                lazy[2*node+1] += diff;
            }
            return;
        }
        ll mid = (start + end) / 2;
        updateRange(2*node, start, mid, l, r, diff);
        updateRange(2*node+1, mid+1, end, l, r, diff);
        treeSum[node] = treeSum[2*node] + treeSum[2*node+1];
        treeMax[node] = max(treeMax[2*node], treeMax[2*node+1]);
    }
    ll querySum(int l, int r) {return querySum(root, 0, n-1, l, r);}
    ll querySum(int node, int start, int end, int l, int r) {
        if(r < start || end < l) return 0;
        pendingUpdate(node, start, end);
        if(l <= start && end <= r) return treeSum[node];
        ll mid = (start+end)/2;
        return querySum(2*node, start, mid, l, r) + querySum(2*node+1, mid+1, end, l, r);
    }
    ll queryMax(int l, int r) {return queryMax(root, 0, n-1, l, r);}
    ll queryMax(int node, int start, int end, int l, int r) {
        if(r < start || end < l) return -1e18;
        pendingUpdate(node, start, end);
        if(l <= start && end <= r) return treeMax[node];
        ll mid = (start+end)/2;
        return max(queryMax(2*node, start, mid, l, r), queryMax(2*node+1, mid+1, end, l, r));
    }
};

int main() {
    int n;
    cin >> n;
    int res = 1;
    const int maxVal = 1000010;
    SegmentTree stinc(maxVal);
    SegmentTree stdec(maxVal);
    for(int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        int mx = 1+stinc.queryMax(val+1, maxVal-1);
        res = max(res, mx);
        
        int currVal = stdec.queryMax(val, val);
        if(currVal < mx) {
            stdec.updateRange(val, val, mx-currVal);
        }
        
        
        mx = 1+stdec.queryMax(0, val-1);
        res = max(res, mx);
        
        currVal = stinc.queryMax(val, val);
        if(currVal < mx) {
            stinc.updateRange(val, val, mx-currVal);
        }
        
    }
    cout << res << '\n';
}
