#include <bits/stdc++.h>

using namespace std;

int totallen = 0;

struct piece {
    int close; // number ')' that need to be satisfied
    int open; // number '(' that need to be satisfied
    int val; // The total length
    string s;
};

bool cmp(piece& x, piece& y) {
    int diffx = x.open - x.close;
    int diffy = y.open - y.close;
    if((diffx > 0) ^ (diffy > 0)) {
        return diffx > diffy;
    }
    if(diffx > 0) {
        if(x.close == y.close) return diffx > diffy;
        return x.close < y.close;
    }
    if(x.open == y.open) return diffx > diffy;
    return x.open > y.open;
}

vector<int> solve(vector<piece> pieces) {
    vector<int> res(totallen+1,0);
    // For each piece
    for(auto p : pieces) {
        if(p.open >= p.close) {
            // For each partial string we can build off of
            for(int j = totallen; j >= 0; j--) {
                // If we don't have enough to use this piece, skip it
                if(p.close > j) continue;

                // If we haven't actually achieved this state, don't use it
                if(res[j] < j) continue;

                // Save this value
                res[j-p.close+p.open] = max(res[j-p.close+p.open],res[j]+p.val);
            }
        }
        else {
            // For each partial string we can build off of
            for(int j = 0; j <= totallen; j++) {
                // If we don't have enough to use this piece, skip it
                if(p.close > j) continue;

                // If we haven't actually achieved this state, don't use it
                if(res[j] < j) continue;

                // Save this value
                res[j-p.close+p.open] = max(res[j-p.close+p.open],res[j]+p.val);
            }
        }
    }
    return res;
}

string rev(string s) {
    for(auto& i : s) {
        if(i == ')') {
            i = '(';
        }
        else {
            i = ')';
        }
    }
    reverse(s.begin(),s.end());
    return s;
}

int getcost(string s) {
    int cost = 0;
    int curr = 0;
    for(auto i : s) {
        if(i == ')') curr++;
        else curr--;
        cost = max(cost,curr);
    }
    return cost;
}

int main() {
    int n;
    cin >> n;

    vector<string> input(n);
    for(auto& i : input) {
        cin >> i;
        totallen += i.size();
    }

    vector<piece> pieces; // split pieces up on their opening

    for(auto i : input) {
        piece p;
        p.s = i;
        p.close = getcost(i);
        p.open = getcost(rev(i));
        p.val = i.size();
        pieces.push_back(p);
    }

    sort(pieces.begin(),pieces.end(),cmp);

    vector<int> res = solve(pieces);
    cout << res[0] << endl;
}
