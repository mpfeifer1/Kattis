#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll solved = 0;
map<ll, int> distforward;
map<ll, int> distbackward;

void setval(ll& state, ll x, ll y, ll val) {
    ll shift1 = ((4 * y) + x) * 2;

    // Unset bits
    state &= ~((ll)3 << shift1);

    // Set new bits
    state |= (val << shift1);
}

ll getval(ll state, ll x, ll y) {
    // Return these bits
    state >>= ((4 * y) + x) * 2;
    return state % 4;
}

ll swipeu(ll b, int col) {
    int temp =        getval(b, 0, col);
    setval(b, 0, col, getval(b, 1, col));
    setval(b, 1, col, getval(b, 2, col));
    setval(b, 2, col, getval(b, 3, col));
    setval(b, 3, col, temp);
    return b;
}

ll swiped(ll b, int col) {
    int temp =        getval(b, 3, col);
    setval(b, 3, col, getval(b, 2, col));
    setval(b, 2, col, getval(b, 1, col));
    setval(b, 1, col, getval(b, 0, col));
    setval(b, 0, col, temp);
    return b;
}

ll swipel(ll b, int col) {
    int temp =        getval(b, col, 0);
    setval(b, col, 0, getval(b, col, 1));
    setval(b, col, 1, getval(b, col, 2));
    setval(b, col, 2, getval(b, col, 3));
    setval(b, col, 3, temp);
    return b;
}

ll swiper(ll b, int col) {
    int temp =        getval(b, col, 3);
    setval(b, col, 3, getval(b, col, 2));
    setval(b, col, 2, getval(b, col, 1));
    setval(b, col, 1, getval(b, col, 0));
    setval(b, col, 0, temp);
    return b;
}

void getstates(vector<ll>& boards, ll& curr) {
    for(int i = 0; i < 4; i++) {
        boards.push_back(swipeu(curr, i));
        boards.push_back(swiped(curr, i));
        boards.push_back(swipel(curr, i));
        boards.push_back(swiper(curr, i));
    }
}

int searchforward(ll& start) {
    queue<ll> q;
    distforward[start] = 0;
    q.push(start);

    while(!q.empty()) {
        ll curr = q.front();
        q.pop();

        if(curr == solved) {
            return distforward[curr];
        }

        vector<ll> boards;
        getstates(boards, curr);

        for(auto& next : boards) {
            if(distforward.count(next) == 0) {
                distforward[next] = distforward[curr] + 1;
                if(distforward[next] < 6) {
                    q.push(next);
                }
            }
        }
    }

    return -1;
}

int searchbackward() {
    queue<ll> q;
    distbackward[solved] = 0;
    q.push(solved);

    while(!q.empty()) {
        ll curr = q.front();
        q.pop();

        if(distforward.count(curr) > 0) {
            return distforward[curr] + distbackward[curr];
        }

        vector<ll> boards;
        getstates(boards, curr);

        for(auto& next : boards) {
            if(distbackward.count(next) == 0) {
                distbackward[next] = distbackward[curr] + 1;
                q.push(next);
            }
        }
    }

    return -1;
}
int main() {
    ll b = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            char c; cin >> c;
            int valhere;
            if(c == 'R') valhere = 0;
            if(c == 'G') valhere = 1;
            if(c == 'B') valhere = 2;
            if(c == 'Y') valhere = 3;
            setval(b, i, j, valhere);
        }
    }

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            setval(solved, j, i, j);
        }
    }

    if(b == solved) {
        cout << 0 << endl;
        return 0;
    }

    int ans = searchforward(b);
    if(ans == -1) {
        cout << searchbackward() << endl;
    }
    else {
        cout << ans << endl;
    }
}
