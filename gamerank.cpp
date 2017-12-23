#include <bits/stdc++.h>

using namespace std;

int main() {

    unordered_map<int, int> rank_to_star;
    for(int i = 25; i >= 21; i--) {
        rank_to_star[i] = 2;
    }
    for(int i = 20; i >= 16; i--) {
        rank_to_star[i] = 3;
    }
    for(int i = 15; i >= 11; i--) {
        rank_to_star[i] = 4;
    }
    for(int i = 10; i >= 1; i--) {
        rank_to_star[i] = 5;
    }

    string s;
    cin >> s;

    bool legend = false;
    int rank = 25;
    int stars = 0;
    int winstreak = 0;

    for(auto i : s) {
        if(i == 'W') {
            winstreak++;

            // If winstreak
            if(rank >= 6 && winstreak >= 3) {
                stars++;
                if(rank_to_star[rank]+1 == stars) {
                    rank--;
                    stars = 1;
                }
            }

            // Normal star
            stars++;
            if(rank_to_star[rank]+1 == stars) {
                rank--;
                stars = 1;
            }

            // Check legend
            if(rank == 0) {
                legend = true;
            }

        }
        else {
            winstreak = 0;
            if(rank <= 20) {
                stars--;
            }
            if(stars == -1) {
                if(rank == 20) {
                    stars = 0;
                }
                else {
                    rank++;
                    stars = rank_to_star[rank]-1;
                }
            }
        }
    }

    if(legend) {
        cout << "Legend" << endl;
    }
    else {
        cout << rank << endl;
    }
}
