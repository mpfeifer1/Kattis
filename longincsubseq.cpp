#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> v, vector<int>& t, int l, int r, int key) {
    // Binary search
    while(r-l > 1) {
        int m = l + (r-l)/2;
        if(v[t[m]] >= key) {
            r = m;
        }
        else {
            l = m;
        }
    }

    return r;
}

int main() {
    int n;
    while(cin >> n) {
        // If array of size 0, print 0
        if(n == 0) {
            cout << 0 << endl << endl;
            continue;
        }

        // Read in numbers
        vector<int> v;
        for(int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }

        // Initialize result array
        vector<int> r;
        r.resize(n+1, -1);

        // Initialize tail array
        vector<int> t;
        t.resize(n+1, 0);

        // Calculate LIS
        int l = 1;
        for(int i = 1; i < n; i++) {
            if(v[i] < v[t[0]]) {
                t[0] = i;
            }
            else if(v[i] > v[t[l-1]]) {
                r[i] = t[l-1];
                t[l++] = i;
            }
            else {
                int pos = search(v, t, -1, l-1, v[i]);
                r[i] = t[pos-1];
                t[pos] = i;
            }
        }

        // Print length
        cout << l << endl;

        // Calculate LIS
        vector<int> ans;
        for(int i = t[l-1]; i >= 0; i = r[i]) {
            ans.push_back(i);
        }
        reverse(ans.begin(), ans.end());

        // Bug with 1-length LIS
        if(l == 1) {
            while(ans.size() > 1) {
                ans.pop_back();
            }
        }

        // Print LIS
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}
