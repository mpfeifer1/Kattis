#include <iostream>
#include <vector>

using namespace std;

bool tie(string w1, string w2) {
    return w1 == w2;
}

bool won(string w1, string w2) {
    if(w1 == "scissors" && w2 == "paper") {
        return true;
    }
    if(w1 == "rock" && w2 == "scissors") {
        return true;
    }
    if(w1 == "paper" && w2 == "rock") {
        return true;
    }
    return false;
}

int main() {
    int n, k;
    bool first = true;
    while(cin >> n && cin >> k) {
        if(first) {
            first = false;
        }
        else {
            cout << endl;
        }

        int games = k * n * (n-1) / 2;
        vector<int> wins, loss;
        wins.resize(n+1, 0);
        loss.resize(n+1, 0);

        for(int i = 0; i < games; i++) {
            int p1, p2;
            string w1, w2;

            cin >> p1 >> w1 >> p2 >> w2;

            if(!tie(w1, w2)) {
                if(won(w1, w2)) {
                    wins[p1]++;
                    loss[p2]++;
                }
                else {
                    wins[p2]++;
                    loss[p1]++;
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            if(wins[i] == 0 && loss[i] == 0) {
                cout << "-" << endl;
            }
            else {
                cout.precision(3);
                cout << fixed;
                cout << double(wins[i]) / (wins[i] + loss[i]) << endl;
            }
        }
    }
}
