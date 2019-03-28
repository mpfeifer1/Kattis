#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef long long ll;

int n, m;
vector<string> v;

// Returns a 2d array with how far up and right each point can move
vector<vector<int>> getUpRight() {
    vector<vector<int>> res;
    res.resize(2*n+2,vector<int>(2*m+2,0));
    for(int i = 2; i < 2*n && i < v.size(); i++) {
        for(int j = 0; j < 2*m && j+1 < v[i].size(); j++) {
            if(v[i][j] == 'x' && v[i-1][j+1] == '/') {
                res[i][j] = res[i-2][j+2] + 1;
            }
        }
    }
    return res;
}

vector<vector<int>> getUpLeft() {
    vector<vector<int>> res;
    res.resize(2*n+2,vector<int>(2*m+2,0));
    for(int i = 2; i < 2*n && i < v.size(); i++) {
        for(int j = 2; j < 2*m && j < v[i].size(); j++) {
            if(v[i][j] == 'x' && v[i-1][j-1] == '\\') {
                res[i][j] = res[i-2][j-2] + 1;
            }
        }
    }
    return res;
}

struct fenwickTree {
    vector<ll> bit;
    int n;
    fenwickTree() {
        n = (int)12000*2+10;
        bit.assign(n,0);
    }
    ll sum(int r) {
        ll ret = 0;
        for(; r >= 0; r = (r&(r+1))-1)
            ret += bit[r];
        return ret;
    }
    void add(int idx, ll d) {
        if(idx < 0) return;
        for(; idx < n; idx = idx | (idx+1))
            bit[idx] += d;
    }
    ll sum(int l, int r) {
        if(l < 0 || r < 0) return 0;
        if(l > r) return 0;
        return sum(r) - sum(l-1);
    }
};

int count() {
    vector<vector<int>> ur = getUpRight();
    vector<vector<int>> ul = getUpLeft();

    /*
    for(int i = 0; i < 2*n; i++) {
        for(int j = 0; j < 2*m; j++) {
            cout << ur[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < 2*n; i++) {
        for(int j = 0; j < 2*m; j++) {
            cout << ul[i][j] << " ";
        }
        cout << endl;
    }
    */

    int ans = 0;

    for(int i = 0; i < 2*n; i+=2) {
        fenwickTree ft;
        vector<vector<int>> event(2*m+2);
        int left = 0;
        for(int j = (i % 4 == 0)?0:2; j < 2*m; j += 4) {
            ft.add(j,1);
        }
        for(int j = (i % 4 == 0)?0:2; j < 2*m && j < v[i].size(); j += 4) {
            if(j > 0 && v[i][j-1] == '-') {
                left++;
            }
            else {
                left = 0;
            }
            if(v[i][j] != 'x') continue;
            int dx = ur[i][j] * 4;
            if(j+dx < 2*m) {
                event[j+dx].push_back(j);
            }
            ans += ft.sum(j-4*min(ul[i][j],left),j-1);
            for(auto k : event[j]) {
                ft.add(k,-1);
            }
        }
    }

    return ans;
}

void flip() {
    reverse(v.begin(),v.end());

    int mask = '\\' ^ '/';

    for(auto& i : v) {
        for(auto& j : i) {
            if(j == '/' || j == '\\')
                j ^= mask;
        }
    }
}

signed main() {
    cin >> n >> m;
    cin.ignore();
    v.resize(2*n);
    for(auto& i : v) {
        getline(cin,i);
        i.resize(2*m+2,' ');
    }
    v.pop_back();

    if(n % 2 == 0) {
        v.push_back(string(2*m+2,' '));
        v.push_back(string(2*m+2,' '));
        n++;
    }

    int ways = 0;
    ways += count();
    flip();
    ways += count();
    cout << ways << endl;
}
