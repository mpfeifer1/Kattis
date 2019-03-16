#include <bits/stdc++.h>

using namespace std;

int find(vector<int>& d, int a) {
    if(d[a] == -1) return a;
    return d[a] = find(d,d[a]);
}

void join(vector<int>& d, int a, int b) {
    a = find(d,a);
    b = find(d,b);
    if(a == b) return;
    d[a] = b;
}

int main() {
    string s;
    cin >> s;

    int n = s.size();

    int k;
    cin >> k;

    vector<int> d(n,-1);

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(j-i >= k) {
                join(d,j,i);
            }
        }
    }

    vector<deque<char>> chars(n);

    for(int i = 0; i < n; i++) {
        chars[find(d,i)].push_back(s[i]);
    }

    for(auto& i : chars) {
        sort(i.begin(),i.end());
    }

    string res;
    for(int i = 0; i < n; i++) {
        res.push_back(chars[find(d,i)].front());
        chars[find(d,i)].pop_front();
    }
        
    sort(s.begin(),s.end());

    if(s == res) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
