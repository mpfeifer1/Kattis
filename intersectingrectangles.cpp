#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegmentTree {
    vector<ll> tree, lazy;
    ll n, root, size;
    SegmentTree(int currSize) : n(currSize), root(1) {
        ll x = (ll)(ceil(log2(currSize)));
        size = 2*(ll)pow(2,x);
        tree.resize(size, 0);
        lazy.resize(size, 0);
    }
    void pendingUpdate(int node, int start, int end) {
        if(lazy[node]) {
            tree[node] += (end-start+1) * lazy[node];
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
            tree[node] += (end-start+1) * diff;
            if(start != end) {
                lazy[2*node] += diff;
                lazy[2*node+1] += diff;
            }
            return;
        }
        ll mid = (start+end)/2;
        updateRange(2*node, start, mid, l, r, diff);
        updateRange(2*node+1, mid+1, end, l, r, diff);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    ll query(int l, int r) {return query(root, 0, n-1, l, r);}
    ll query(int node, int start, int end, int l, int r) {
        if(r < start || end < l) return 0;
        pendingUpdate(node, start, end);
        if(l <= start && end <= r) return tree[node];
        ll mid = (start+end)/2;
        return query(2*node, start, mid, l, r) + query(2*node+1, mid+1, end, l, r);
    }
};

struct rect {
    int x, y1, y2, ID;
    bool Begin;
};

bool cmp(const rect &i, const rect &j) {
    if(i.x == j.x) {
        return i.y2 - i.y1 < j.y2 - j.y1;
    }
    return i.x < j.x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<rect> arr;
    arr.reserve(2*n);
    for(int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        arr.push_back({x1, y1, y2, i+1, true});
        arr.push_back({x2, y1, y2, i+1, false});
    }
    sort(arr.begin(), arr.end(), cmp);
    //SegmentTree st(comp.size()+10);
    set<pair<int, int>> st;//y val, ID
    int i = 0;
    while(i < arr.size()) {
        int j = i;
        vector<rect> begins, ends;
        while(j < arr.size() && arr[j].x == arr[i].x) {
            if(arr[j].Begin) {
                begins.push_back(arr[j]);
            } else {
                ends.push_back(arr[j]);
            }
            ++j;
        }
        for(auto &r : begins) {
            //r.y1 = r.y2
            auto it1 = st.lower_bound({r.y1, -1});
            if(it1 != st.end() && it1->first <= r.y2) {
                //cout << "here, insert: " << r.y1 << ' ' << r.y2 << '\n';
                cout << "1\n";
                return 0;
            }
            st.insert({r.y1, r.ID});
            st.insert({r.y2, r.ID});
        }
        for(auto &r : ends) {
            st.erase({r.y1, r.ID});
            st.erase({r.y2, r.ID});
            auto it1 = st.lower_bound({r.y1, -1});
            if(it1 != st.end() && it1->first <= r.y2) {
                //cout << "here, erase: " << r.y1 << ' ' << r.y2 << '\n';
                cout << "1\n";
                return 0;
            }
        }
        i = j;
    }
    cout << "0\n";
}
