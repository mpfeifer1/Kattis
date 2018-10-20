#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct KMP_Match {
    vector<int> T;
    string pat;
    KMP_Match() {};
    KMP_Match(string pattern) : pat(pattern) {this->buildTable(pat);};
    void buildTable(string pattern) {
        pat = pattern;
        T.clear();
        T.resize(pat.length()+1);
        int i = 0, j = -1;
        T[i] = j;
        while(i < pat.size()) {
            while(j >= 0 && pat[i] != pat[j]) j = T[j];
            i++, j++;
            T[i] = j;
        }
    }
    vector<int> find(string txt, bool all = false) {
        int m = 0, i = 0;
        vector<int> matches;
        while(true) {
            if(m+i >= txt.size() || pat[i] == txt[m+i]) {
                if(i == pat.length()-1) {
                    matches.push_back(m);
                    if(!all) return matches;
                    m = m + i - T[i];
                    i = T[i];
                }
                i++;
            } else {
                if(T[i] != -1) {
                    m = m + i - T[i];
                    i = T[i];
                } else {
                    i = 0;
                    m++;
                }
            }
        }
        return matches;
    }
};

int fail[1000005];

bool KMPints(vector<ll> a, vector<ll> b){
    for(int i = 0; i < a.size(); i++) {
        b.push_back(b[i]);
    }
    int p = 0;
    for(int i = 1; i < a.size(); i++) {
        while(p && a[i] != a[p]) p = fail[p];
        if(a[i] == a[p]) p++;
        fail[i + 1] = p;
    }
    p = 0;
    for(auto &i : b) {
        while(p && i != a[p]) p = fail[p];
        if(i == a[p]) p++;
        if(p == a.size()) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string a;
    cin >> a;

    KMP_Match kmp(a);

    a.erase(0,1);

    vector<int> matches = kmp.find(a);

    cout << matches[0]+1 << endl;
    return 0;
}

