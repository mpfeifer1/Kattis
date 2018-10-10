#include <bits/stdc++.h>

using namespace std;

void findspaces(vector<vector<int>>& out, vector<int>& lengths, int width) {
    out.push_back({});

    int currlen = 0;
    for(auto& i : lengths) {
        if(currlen + i > width) {
            out.push_back({});
            currlen = 0;
        }

        currlen += i;
        out.back().push_back(currlen);
        currlen++;
    }

    for(auto& i : out) {
        if(i.size() > 0) {
            i.pop_back();
        }
    }
}

int riverlength(vector<vector<int>>& spaces) {
    int best = 0;

    int biggest = 0;
    for(auto& i : spaces) {
        biggest = max(biggest, i.back());
    }
    biggest += 2;

    vector<int> updated(biggest, -2);
    vector<int> prevval(biggest, 0);

    int ct = 0;
    for(auto& line : spaces) {
        for(auto& space : line) {
            int val = 1;

            for(int i = -1; i <= 1; i++) {

                if(updated[space+i]+1 < ct) {
                    prevval[space+i] = 0;
                    updated[space+i] = ct;
                }

                val = max(val, prevval[space+i]+1);
            }

            prevval[space] = val;
            updated[space] = ct;
            best = max(best, val);
        }

        ct++;
    }

    return best;
}

int main() {
    int n;
    cin >> n;

    vector<int> v;
    int longest = 0;
    int total = 0;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s.size());
        longest = max(longest, (int)s.size());
        total += s.size() + 1;
    }

    int idx = 0;
    int river = -1;
    vector<vector<int>> old;
    for(int i = longest; i < total; i++) {
        vector<vector<int>> spaces;
        findspaces(spaces, v, i);

        bool same = true;
        if(old.size() == spaces.size()) {
            for(int i = 0; i < old.size(); i++) {
                if(old[i].size() != spaces[i].size()) {
                    same = false;
                }
            }
            if(same) continue;
        }
        old = spaces;

        int var = spaces.size();
        if(var <= river) {
            break;
        }

        int riverhere = riverlength(spaces);
        if(riverhere > river) {
            river = riverhere;
            idx = i;
        }
    }

    cout << idx << " " << river << endl;
}
