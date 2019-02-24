#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    int dx1 = b.first - a.first;
    int dy1 = b.second - a.second;
    int dx2 = c.first - a.first;
    int dy2 = c.second - a.second;
    return dx1 * dy2 - dy1 * dx2;
}

ld ax = 0;
ld ay = 0;

bool cmp(pair<int,int> p1, pair<int,int> p2) {
    assert(p1.second-ay != 0 || p1.first-ax != 0);
    assert(p2.second-ay != 0 || p2.first-ax != 0);
    ld val1 = atan2(p1.second-ay,p1.first-ax);
    ld val2 = atan2(p2.second-ay,p2.first-ax);
    return val1 < val2;
}

void sortpoly(vector<pair<int,int>>& v) {
    for(auto i : v) {
        ax += i.first;
        ay += i.second;
    }

    ax /= v.size();
    ay /= v.size();

    sort(v.begin(),v.end(),cmp);
}

struct setsize {
    bool operator()(const set<int>& s1, const set<int>& s2) {
        if(s1.size() == s2.size()) {
            return s1 < s2;
        }
        return s1.size() < s2.size();
    }
};

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> v(n);
    for(auto& i : v) {
        cin >> i.first >> i.second;
    }
    sortpoly(v);

    priority_queue<set<int>,vector<set<int>>,setsize> pq;
    for(int i = 0; i < n; i++) {
        set<int> segment;
        for(int j = 0; j < n; j++) {
            if(ccw(v[i],v[(i+1)%n],v[(i+j)%n]) == 0) {
                segment.insert((i+j)%n);
            }
        }
        pq.push(segment);
    }

    int lines = 0;
    int leftover = 0;
    vector<bool> used(n,false);
    while(!pq.empty()) {
        set<int> seg = pq.top();
        pq.pop();

        bool works = true;
        set<int> next;
        for(auto i : seg) {
            if(used[i]) {
                works = false;
            }
            else {
                next.insert(i);
            }
        }

        if(works) {
            for(auto i : seg) {
                used[i] = true;
            }
            if(seg.size() == 1) {
                leftover++;
                continue;
            }
            lines++;
        }
        else {
            if(next.size() > 0) {
                pq.push(next);
            }
        }
    }

    cout << lines + ((leftover+1)/2) << endl;
}
