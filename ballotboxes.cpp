#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

typedef long long ll;

class mycomparison {
    public:
    bool operator() (const pair<ll,ll>& lhs, const pair<ll,ll>& rhs) const {
        if(ceil(lhs.first / double(lhs.second)) == ceil(rhs.first / double(rhs.second))) {
            return lhs.second > rhs.second;
        }
        return ceil(lhs.first / double(lhs.second)) < ceil(rhs.first / double(rhs.second));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, b;
    while(cin >> n && cin >> b && !(n == -1 || b == -1)) {
        priority_queue<pair<ll, ll>, vector<pair<ll,ll>>, mycomparison> q;

        for(ll i = 0; i < n; i++) {
            ll temp;
            cin >> temp;
            q.push({temp, 1});
        }

        b -= n;

        for(ll i = 0; i < b; i++) {
            pair<int, int> p = q.top();
            q.pop();
            p.second++;
            q.push(p);
        }

        cout << ceil(q.top().first / double(q.top().second)) << endl;
    }
}
