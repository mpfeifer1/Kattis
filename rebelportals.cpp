#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
ld inf = 1e10;

struct pt {
    ld x, y, z;
};

ld dist(pt p1, pt p2) {
    return sqrt(pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2) + pow(p1.z-p2.z,2));
}

vector<vector<vector<ld>>> memo;

int main() {
    int n;
    cin >> n;
    vector<pt> v(n);
    for(auto& i : v) {
        cin >> i.x >> i.y >> i.z;
    }

    vector<vector<ld>> d(n,vector<ld>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            d[i][j] = dist(v[i],v[j]);
        }
    }

    // memo[subset][portal][currnode]
    memo.resize((1<<n), vector<vector<ld>>(2,vector<ld>(n,inf)));
    memo[0][1][0] = 0;

    // For each state
    for(int i = 1; i < (1<<n); i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < n; k++) {

                // Make the state easier to read
                int currsubset = i;
                int currportal = j;
                int currnode = k;

                //cout << "processing " << currsubset << " " << currportal << " " << currnode << endl;
                for(int l = 0; l < n; l++) {
                    if(i & (1<<l)) {
                        ld weight = d[k][l];

                        int prevsubset = currsubset ^ (1 << l);

                        if(j == 1) {
                            if(memo[currsubset][currportal][currnode] > memo[prevsubset][currportal^1][l] + 0) {
                                memo[currsubset][currportal][currnode] = memo[prevsubset][currportal^1][l] + 0;
                            }
                        }
                        if(memo[currsubset][currportal][currnode] > memo[prevsubset][currportal^1][l] + weight) {
                            memo[currsubset][currportal][currnode] = memo[prevsubset][currportal^1][l] + weight;
                        }
                        if(memo[currsubset][currportal][currnode] > memo[prevsubset][currportal][l] + weight) {
                            memo[currsubset][currportal][currnode] = memo[prevsubset][currportal][l] + weight;
                        }
                    }
                }

            }
        }
    }

    /*
    for(int i = 0; i < (1<<n); i++) {
        for(int j = 0; j < n; j++) {
            cout << memo[i][1][j] << " ";
        }
        cout << endl;
    }
    */

    cout << fixed;
    cout.precision(9);
    cout << memo[(1<<n)-1][1][0] << endl;
}


