#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//jobs X workers cost matrix
//cost[i][j] is cost of job i done by worker j
//#jobs must be <= #workers
//Default finds max cost; to find min cost set all costs[i][j] to -costs[i][j]
//Adapted from the judges solution to cordonbleu from SWERC 2017
ll HungarianMatch(const vector<vector<ll>>& costs)
{
    ll nx = costs.size();
    ll ny = costs[0].size();

    vector<ll> xy(nx, -1), yx(ny, -1), lx(nx), ly(ny, 0), augmenting(ny);
    vector<bool> s(nx);
    vector<pair<ll, ll>> slack(ny, make_pair(0, 0));

    for (ll x = 0; x < nx; x++)
    {
        ll& lxx = lx[x];
        lxx = costs[x][0];
        for(const ll& i : costs[x])
            lxx = max(lxx, i);
    }

    for (ll root = 0; root < nx; root++) {
        fill(augmenting.begin(), augmenting.end(), -1);
        fill(s.begin(), s.end(), false);

        s[root] = true;
        auto lxroot = lx[root]; auto criter = costs[root].begin();
        auto lyiter = ly.begin(); auto sliter = slack.begin();
        for (ll y = 0; y < ny; y++, criter++, lyiter++, sliter++)
        *sliter = make_pair(lxroot + *lyiter - *criter, root);

        ll y = -1;
        for (;;) {
        ll delta = numeric_limits<ll>::max(), x = -1;
        auto aiter = augmenting.begin(); auto sliter = slack.begin();
        for (ll yy = 0; yy < ny; yy++, aiter++, sliter++)
            if (*aiter == -1 && sliter -> first < delta) {
                delta = sliter->first;
                x = sliter->second;
                y = yy;
            }

        if (delta > 0) {
            auto siter = s.begin(); auto lxiter = lx.begin();
            for (ll x = 0; x < nx; x++, siter++, lxiter++)
                if (*siter)
                    *lxiter -= delta;

            aiter = augmenting.begin(); lyiter = ly.begin(); sliter = slack.begin();
            for (ll y = 0; y < ny; y++, lyiter++, aiter++, sliter++)
                if (*aiter > -1)
                    *lyiter += delta;
                else
                    sliter->first -= delta;
        }

        augmenting[y] = x;
        x = yx[y];
        if (x == -1)
            break;
        s[x] = true;

        aiter = augmenting.begin(); sliter = slack.begin();
        auto lxx = lx[x]; lyiter = ly.begin();
        auto cxiter = costs[x].begin();
        for (ll y = 0; y < ny; y++, aiter++, sliter++, lyiter++, cxiter++)
            if (*aiter == -1) {
                pair<ll, ll> alt = make_pair(lxx + *lyiter - *cxiter, x);
                if (sliter->first > alt.first)
                    *sliter = alt;
                }
            }

        while (y > -1) {
            int x = augmenting[y];
            int prec = xy[x];
            yx[y] = x;
            xy[x] = y;
            y = prec;
        }
    }
    return -(accumulate(lx.cbegin(), lx.cend(), 0) + accumulate(ly.cbegin(), ly.cend(), 0));
}

ll dist(pair<ll,ll>& p1, pair<ll,ll>& p2) {
    return abs(p1.first-p2.first) +
           abs(p1.second-p2.second);
}

int main(){
    ll n, m;
    cin >> n >> m;

    vector<pair<ll,ll>> bottles(n);
    vector<pair<ll,ll>> couriers(m);
    for(auto& i : bottles) {
        cin >> i.first >> i.second;
    }
    for(auto& i : couriers) {
        cin >> i.first >> i.second;
    }

    pair<ll,ll> restaraunt;
    cin >> restaraunt.first >> restaraunt.second;

    vector<vector<ll>> costs;
    costs.resize(n,vector<ll>(n+m-1));

    // For each bottle
    for(ll i = 0; i < n; i++) {
        // For each courier
        for(ll j = 0; j < n+m-1; j++) {
            ll a = j + n;
            ll costhere = 0;
            // Actual courier
            if(j < m) {
                costhere += dist(bottles[i],couriers[j]);
                costhere += dist(bottles[i],restaraunt);
            }
            // Restaraunt and back
            else {
                costhere += 2 * dist(bottles[i],restaraunt);
            }
            costs[i][j] = -costhere;
        }
    }

    cout << HungarianMatch(costs) << endl;
}
