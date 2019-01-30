#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool colinear(pair<ll,ll>& p1, pair<ll,ll>& p2, pair<ll,ll>& p3) {
    return (p2.first - p1.first) * (p3.second - p1.second) == (p2.second - p1.second) * (p3.first - p1.first);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    if(n <= 4) {
        cout << "success" << endl;
        return 0;
    }

    vector<pair<ll,ll>> p(n);
    for(auto& i : p) {
        cin >> i.first >> i.second;
    }

    bool found = false;
    int p1,p2,p3;

    for(int i = 0; i < 5; i++) {
        for(int j = i+1; j < 5; j++) {
            for(int k = j+1; k < 5; k++) {
                if(colinear(p[i],p[j],p[k])) {
                    found = true;
                    p1=i;p2=j;p3=k;
                }
            }
        }
    }

    if(!found) {
        cout << "failure" << endl;
        return 0;
    }

    vector<pair<ll,ll>> r;
    for(auto i : p) {
        if(!colinear(p[p1],p[p2],i)) {
            r.push_back(i);
        }
    }

    bool works = true;
    for(int i = 2; i < r.size(); i++) {
        if(!colinear(r[i-0],r[i-1],r[i-2])) {
            works = false;
            break;
        }
    }

    if(works) {
        cout << "success" << endl;
    }
    else {
        cout << "failure" << endl;
    }
}
