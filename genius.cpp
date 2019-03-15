#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

struct tourn {
    vector<int> players;
};

// Probability p1 beats p2
ld beat(vector<int>& players, int p1, int p2) {
    return (ld)players[p1] / (players[p1]+players[p2]);
}

// players contains us, our first opponent, our two choices
ld dotourn(vector<int> players) {

    ld win1 = beat(players,0,1);
    ld win2 = beat(players,2,3);

    ld win3 = beat(players,0,2);
    ld win4 = beat(players,0,3);

    ld actual = win1 * ((win2*win3)+((1-win2)*win4));

    return actual;
}

ld getprob(tourn t, int x) {
    vector<int> v;
    v.push_back(t.players[x]);
    v.push_back(t.players[x^1]);
    v.push_back(t.players[x^2]);
    v.push_back(t.players[x^2^1]);
    return dotourn(v);
}

int main() {
    int k, t, p, q, x;
    cin >> k >> t >> p >> q >> x;

    vector<tourn> tourns(t);
    for(auto& i : tourns) {
        i.players.resize(4);
        for(auto& j : i.players) {
            cin >> j;
        }
    }

    // memo[#guesses][#correct] = prob
    vector<vector<ld>> memo;
    memo.resize(t+1,vector<ld>(t+1,0));
    memo[0][0] = 1;

    // For each tournament,
    for(int i = 1; i <= t; i++) {
        // Calculate the probability of his guess winning
        ld prob = getprob(tourns[i-1],(x%4));

        // Update the memo table
        for(int j = 0; j < t; j++) {
            memo[i][j] += memo[i-1][j] * (1-prob);
            memo[i][j+1] += memo[i-1][j] * prob;
        }

        // Calculate the next person he will guess
        x *= p;
        x %= q;
    }

    /* Debugging - dump percentage array
    for(int i = 0; i <= t; i++) {
        for(int j = 0; j <= t; j++) {
            cout << memo[i][j] << " ";
        }
        cout << endl;
    }
    */

    // Sum up the answer
    ld ans = 0;
    for(int i = k; i <= t; i++) {
        ans += memo[t][i];
    }

    cout << fixed;
    cout.precision(8);
    cout << ans << endl;
}
