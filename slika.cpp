#include <bits/stdc++.h>

using namespace std;

int n;

int find(vector<int>& d, int a) {
    if(d[a] < 0) return a;
    return d[a] = find(d, d[a]);
}

void join(vector<int>& d, int a, int b) {
    if(a < 0 || a >= n || b < 0 || b >= n) return;
    a = find(d, a);
    b = find(d, b);
    if(a == b) return;
    d[b] = min(d[b], d[a]);
    d[a] = b;
}

int getnext(vector<int>& d, int a) {
    a = find(d, a);
    return (-d[a]) - 1;
}

struct op {
    int type; // 0 = paint, 1 = save, 2 = load
    int color;
    int x1, y1, x2, y2;
    int target; // idx in array you go to on load
};

vector<vector<int>> create(vector<op>& updates) {
    // Create disjoint sets that represents the image
    vector<vector<int>> v(n, vector<int>(n));
    vector<vector<int>> actual(n, vector<int>(n));

    // Set up disjoint set so that they all contain their own index (+1)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            v[i][j] = -(j+1);
            actual[i][j] = -1;
        }
    }

    // Process all the squares
    for(auto operation : updates) {
        // Grab the data from this operation
        int x1 = operation.x1;
        int x2 = operation.x2;
        int y1 = operation.y1;
        int y2 = operation.y2;
        int color = operation.color;

        // For each row in the square
        for(int i = x1; i <= x2; i++) {
            int j = y1;
            // Process up to y2
            while(j <= y2) {
                // Set color here, jump to next
                if(actual[i][j] < 0) {
                    // Color, join
                    actual[i][j] = color;
                    if(j-1 >= 0 && actual[i][j-1] >= 0) {
                        join(v[i], j-1, j);
                    }
                    if(j+1 < n && actual[i][j+1] >= 0) {
                        join(v[i], j+1, j);
                    }
                    j++;
                }
                else {
                    // Jump to next
                    j = getnext(v[i], j) + 1;
                }
            }
        }
    }

    // If anything hasn't been colored, make it color 1
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(actual[i][j] < 0) {
                actual[i][j] = 1;
            }
        }
    }

    // Return the built array
    return actual;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int k, m;
    cin >> n >> k >> m;

    // Read in input, set up backtracking
    vector<op> v;
    vector<int> saves;
    for(int i = 0; i < m; i++) {
        op o;
        string s;
        cin >> s;
        if(s == "PAINT") {
            o.type = 0;
            cin >> o.color >> o.x1 >> o.y1 >> o.x2 >> o.y2;
        }
        if(s == "SAVE") {
            o.type = 1;
            saves.push_back(i);
        }
        if(s == "LOAD") {
            int t;
            cin >> t;
            o.type = 2;
            o.target = saves[t-1];
        }
        v.push_back(o);
    }

    // Go backwards, keeping all operations in the line
    vector<op> actual;
    for(int i = m-1; i >= 0; i--) {
        if(v[i].type == 0) {
            actual.push_back(v[i]);
        }
        if(v[i].type == 2) {
            i = v[i].target;
        }
    }

    // Split the queries by even and odd
    vector<op> even_update, odd_update;
    for(auto i : actual) {
        if((i.x1 + i.y1) % 2 == 0) {
            even_update.push_back(i);
        }
        else {
            odd_update.push_back(i);
        }
    }

    // Build both arrays from their updates
    vector<vector<int>> even = create(even_update);
    vector<vector<int>> odd = create(odd_update);

    // Print out the answer
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if((i+j) % 2 == 0) {
                cout << even[i][j] << " ";
            }
            else {
                cout << odd[i][j] << " ";
            }
        }
        cout << endl;
    }
}
