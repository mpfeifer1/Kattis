#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> commands;
    int k, c;
    cin >> k >> c;

    for(int i = 0; i < c; i++) {
        cin.ignore();
        if(cin.peek() == 'u') {
            string undo;
            cin >> undo;
            int drops;
            cin >> drops;
            for(int i = 0; i < drops; i++) {
                commands.pop_back();
            }
        }
        else {
            int n;
            cin >> n;
            commands.push_back(n);
        }
    }

    int spot = 0;

    for(auto i : commands) {
        spot += i;
        spot %= k;
        while(spot < 0) {
            spot += k;
        }
    }

    cout << spot << endl;
}
