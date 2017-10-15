#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& conn, int i) {
    if(conn[i] < 0) {
        return i;
    }

    conn[i] = find(conn, conn[i]);
    return conn[i];
}

void join(vector<int>& conn, int a, int b) {
    a = find(conn, a);
    b = find(conn, b);

    if(a == b) {
        return;
    }

    conn[b] = a;
}

int main() {
    int cases;
    cin >> cases;

    vector<int> conn;

    while(cases--) {
        // Read in input
        int cities, roads;
        cin >> cities >> roads;

        // Clear old roads
        conn.clear();
        conn.resize(cities, -1);

        // Connect each set of roads
        for(int i = 0; i < roads; i++) {
            int r1, r2;
            cin >> r1 >> r2;
            join(conn, r1, r2);
        }

        // Count the roads needed
        int extras = 0;
        for(int i = 1; i < cities; i++) {
            if(find(conn, 0) != find(conn, i)) {
                join(conn, 0, i);
                extras++;
            }
        }
        cout << extras << endl;
    }
}
