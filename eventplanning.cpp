#include <iostream>

using namespace std;

int main() {
    int participants, budget, hotels, weekends;
    cin >> participants >> budget >> hotels >> weekends;

    int bestprice = budget+1;

    for(int i = 0; i < hotels; i++) {
        int cost;
        cin >> cost;

        for(int j = 0; j < weekends; j++) {
            int rooms;
            cin >> rooms;

            if(rooms >= participants) {
                bestprice = min(bestprice, participants*cost);
            }
        }
    }

    if(bestprice <= budget) {
        cout << bestprice << endl;
    }
    else {
        cout << "stay home" << endl;
    }
}
