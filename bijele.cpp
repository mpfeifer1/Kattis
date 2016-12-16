#include <iostream>

using namespace std;

int main() {
    int king;
    int queens;
    int rooks;
    int bishops;
    int knights;
    int pawns;
    cin >> king >> queens >> rooks >> bishops >> knights >> pawns;

    cout << 1 - king << " " << 1 - queens << " " << 2 - rooks << " " << 2 - bishops << " " << 2 - knights << " " << 8 - pawns << endl;

    return 0;
}
