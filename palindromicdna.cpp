#include <bits/stdc++.h>

using namespace std;

vector<int> p;
int find(int x) {return p[x] < 0 ? x : p[x] = find(p[x]);}
void merge(int x, int y) {
    if((x=find(x)) == (y=find(y))) return;
    if(p[y] < p[x]) swap(x,y);
    p[x] += p[y];
    p[y] = x;
}


struct twosat {
    int n;
    vector<vector<int> > adj, adjInv;
    vector<int> scc;
    int sccID;
    vector<bool> visited, assignment;

    twosat(int nodes) {
        n = 2*nodes;
        adj.resize(n);
        adjInv.resize(n);
        scc.resize(n);
        assignment.resize(n/2);
    }
    
    //X AND Y = (X OR X) AND (Y OR Y)
    //X NAND Y = (!X OR !Y)
    //X NOR Y = (!X OR !X) AND (!Y OR !Y)
    //X XOR Y = (X OR Y) AND (!X OR !Y)
    //X XNOR Y = (!Y OR X) AND (!X OR Y)
    void add(int i, bool statusI, int j, bool statusJ) {
        const int from1 = i+(!statusI)*(n/2);
        const int to1 = j+statusJ*(n/2);
        adj[from1].push_back(to1);
        adjInv[to1].push_back(from1);
        const int from2 = j+(!statusJ)*(n/2);
        const int to2 = i+statusI*(n/2);
        adj[from2].push_back(to2);
        adjInv[to2].push_back(from2);
    }
    
    void dfs1(int curr, stack<int> &seen) {
        visited[curr] = true;
        for(int x : adj[curr]) {
            if(!visited[x]) {
                dfs1(x, seen);
            }
        }
        seen.push(curr);
    }

    void dfs2(int curr) {
        visited[curr] = true;
        scc[curr] = sccID;
        for(int x : adjInv[curr]) {
            if(!visited[x]) {
                dfs2(x);
            }
        }
    }

    bool solve() {
        visited.resize(n+1,false);
        stack<int> seen;
        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                dfs1(i, seen);
            }
        }
        visited.clear();
        visited.resize(n+1,false);
        sccID = 0;
        while(!seen.empty()) {
            while(!seen.empty() && visited[seen.top()]) seen.pop();
            if(!seen.empty()) {
                dfs2(seen.top());
                sccID++;
            }
        }
        for(int i = 0; i < n/2; ++i) {
            if(scc[i] == scc[i+n/2]) {
                return false;
            }
            assignment[i] = scc[i] < scc[i+n/2];
        }
        return true;
    }
};

void solve(int n, int m) {
    p.clear();
    p.resize(n,-1);
    string s;
    cin >> s;
    vector<vector<int>> sets(m);
    for(int i = 0; i < m; ++i) {
        int len;
        char colon;
        cin >> len >> colon;
        sets[i].resize(len);
        for(int j = 0; j < len; ++j) {
            cin >> sets[i][j];
        }
        for(int j = 0; j < len; ++j) {
            merge(sets[i][j], sets[i][len-j-1]);
        }
    }
    vector<vector<int>> same(n);
    for(int i = 0; i < n; ++i) {
        same[find(i)].push_back(i);
    }

    twosat ts(6*n);
    string dna = "AGTC";
    vector<int> toPos(400);
    for(int i = 0; i < 4; ++i) {
        toPos[dna[i]] = i;
    }
    
    for(int i = 0; i < n; ++i) {
        if(same[i].size() == 0 ) continue;
        //cout << "set:\n";
        //for(int pos : same[i]) cout << pos << ' ';cout << '\n';
        set<char> letters;
        for(int pos : same[i]) {
            letters.insert(s[pos]);
        }
        if(letters.size() == 4) {
            cout << "NO\n";
            return;
        }
        if(letters.size() == 3) {
            int let;
            for(int curr = 0; curr < 4; ++curr) {
                bool good = true;
                for(char c : letters) {
                    if(toPos[c] == curr) {
                        good = false;
                        break;
                    }
                }
                if(good) {
                    let = curr;
                }
            }
            let = (let+2)%4;
            //cout << "here, let: " << dna[let] << '\n';
            ts.add(i*4+let, true, i*4+let, true);
        }
        
        if(letters.size() == 2) {
            int let1 = toPos[*letters.begin()];
            int let2 = toPos[*letters.rbegin()];
            if(let1 > let2) swap(let1, let2);
            if(abs(let1-let2) == 1 || (let1 == 0 && let2 == 3)) {
                ts.add(i*4+let1, true, i*4+let2, true);
            }
            else {
                let1++;
                let1 %= 4;
                let2++;
                let2 %= 4;
                ts.add(i*4+let1, true, i*4+let2, true);
            
            }
        }
    }


    for(int i = 0; i < n; ++i) {
        int pos = toPos[s[i]];
        ts.add(find(i)*4+((pos+2)%4), false, find(i)*4+((pos+2)%4), false);
    }
    
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < 4; ++j) {
            if(toPos[s[i-1]] == j) continue;
            if(toPos[s[i-1]] == ((j+2)%4)) continue;
            for(int k = 0; k < 4; ++k) {
                if(toPos[s[i]] == k) continue;
                if(toPos[s[i]] == ((k+2)%4)) continue;
                ts.add(find(i-1)*4+j, false, find(i)*4+k, false);
            }
        }
    }
    
    
    
    cout << (ts.solve()?"YES\n":"NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    while(cin >> n >> m && (n>0 || m>0)) {
        solve(n,m);
    }
    
}
