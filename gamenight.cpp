#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int A = 0, B = 0, C = 0;
    for(char c : s) {
        A += (c == 'A');
        B += (c == 'B');
        C += (c == 'C');
    }
    s += s;
    vector<vector<int>> prefix(3, vector<int>(n*2));
    for(int let = 0; let < 3; ++let) {
        prefix[let][0] = (s[0] == 'A'+let);
    }
    for(int let = 0; let < 3; ++let) {
        for(int i = 1; i < n+n; ++i) {
            prefix[let][i] = (s[i] == 'A'+let) + prefix[let][i-1];
        }
    }
    int res = n;
    for(int startA = 0; startA+n <= n+n; ++startA) {
        int startB = startA+A;
        int startC = startB+B;
        int moveA = prefix[0][startA+A-1];
        if(startA-1 >= 0) {
            moveA -= prefix[0][startA-1];
        }
        moveA = A-moveA;

        int moveB = prefix[1][startB+B-1];
        if(startB-1 >= 0) {
            moveB -= prefix[1][startB-1];
        }
        moveB = B-moveB;


        int moveC = prefix[2][startC+C-1];
        if(startC-1 >= 0) {
            moveC -= prefix[2][startC-1];
        }
        moveC = C-moveC;
        res = min(res, moveA+moveB+moveC);
    }

    for(int startA = 0; startA+n <= n+n; ++startA) {
        int startC = startA+A;
        int startB = startC+C;
        int moveA = prefix[0][startA+A-1];
        if(startA-1 >= 0) {
            moveA -= prefix[0][startA-1];
        }
        moveA = A-moveA;

        int moveB = prefix[1][startB+B-1];
        if(startB-1 >= 0) {
            moveB -= prefix[1][startB-1];
        }
        moveB = B-moveB;


        int moveC = prefix[2][startC+C-1];
        if(startC-1 >= 0) {
            moveC -= prefix[2][startC-1];
        }
        moveC = C-moveC;
        res = min(res, moveA+moveB+moveC);
    }

    cout << res << '\n';
    return 0;
}
